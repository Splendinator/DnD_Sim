#include "Map.h"



Map::Map(float unitRadius, vector<CollisionShape *> *impassables, vector<CollisionShape *> *rubble) {

	CollisionData cd;
	Vector3 pos;

	//Generate map using a given circle collider.
	for (int j = 0; j < MAP_HEIGHT; ++j) {
		for (int i = 0; i < MAP_WIDTH; ++i) {

			pos = Vector3(MAP_TOP_LEFT.x + i*MAP_TILE_SIZE, MAP_TOP_LEFT.y - j*MAP_TILE_SIZE, 0);

			for (vector<CollisionShape *>::iterator it = impassables->begin(); it != impassables->end(); ++it) {
				if (CollisionCircle(INFINITY,pos, unitRadius).collidedWith(*it, cd)) {
					cout << "#";
					mapData[j * MAP_WIDTH + i] = 0;
					goto e;					
				}
			}
			for (vector<CollisionShape *>::iterator it = rubble->begin(); it != rubble->end(); ++it) {
				if (CollisionCircle(INFINITY, pos, unitRadius).collidedWith(*it, cd)) {
					cout << "^";
					mapData[j * MAP_WIDTH + i] = RUBBLE_SPEED;
					goto e;
				}
			}

			cout << ".";
			mapData[j * MAP_WIDTH + i] = SPEED;

		e:
			true;
			
		}
		cout << endl;
	}

	initNodes();

}

Vector2 Map::getTile(Vector3 pos)
{
	return Vector2(int((pos.x - MAP_TOP_LEFT.x) / MAP_TILE_SIZE), int((MAP_TOP_LEFT.y - pos.y)  / MAP_TILE_SIZE));
}


void Map::genRoute(EntityAI & e, Vector3 pos)
{
	Vector2 start = getTile(pos);
	Vector2 end = getTile(e.getPhysicsNode().getPosition());

	if (start.x == end.x && start.y == end.y) return;	//Handle edge case that you are already on correct tile.

	Node* temp;

	resetNodes();
	

	int sx = start.x, 
		sy = start.y, 
		ex = end.x, 
		ey = end.y;
	
	for (int i = 0; i < MAP_WIDTH * MAP_HEIGHT; ++i) {
		n[i].distance = 0;
	}
	
	//n[sy * MAP_WIDTH + sx].pos = e.getPhysicsNode().getPosition();

	n[sy * MAP_WIDTH + sx].length = 0;
	n[sy * MAP_WIDTH + sx].updateNeighbors();


	//While a path has not yet been found...
	while (!n[ey * MAP_WIDTH + ex].previous) {
		
		if (v->empty()) return;

		temp = v->front();
		v->erase(v->begin());
		temp->updateNeighbors();

;
	}
	
	
	//Work backwards from end node to find optimal path.
	while (n[ey * MAP_WIDTH + ex].previous != nullptr) {

		e.moves.insert(e.moves.end(), n[ey * MAP_WIDTH + ex].pos);
		
		end = getTile(n[ey * MAP_WIDTH + ex].previous->pos);
		ex = end.x;
		ey = end.y;
	}

	//Less robotic by changing end and start positions to world coords instead of grid coords.
	if (e.moves.size() >= 2) {
		e.moves.erase(e.moves.begin());
		e.moves.erase(e.moves.end() - 1);
		e.moves.insert(e.moves.begin(), e.getPhysicsNode().getPosition());
		e.moves.insert(e.moves.end(), pos);
	}


}

Map::~Map()
{
}

void Map::resetNodes()
{
	v->clear();
	for (int j = 0; j < MAP_HEIGHT; ++j) {
		for (int i = 0; i < MAP_WIDTH; ++i) {
			n[j * MAP_WIDTH + i].length = INFINITY;
			n[j * MAP_WIDTH + i].previous = nullptr;
		}
	}
}

void Map::initNodes() {

	for (int j = 0; j < MAP_HEIGHT; ++j) {
		for (int i = 0; i < MAP_WIDTH; ++i) {
			n[j * MAP_WIDTH + i].m = this;
			n[j * MAP_WIDTH + i].weight = mapData[j * MAP_WIDTH + i];
			n[j * MAP_WIDTH + i].pos = Vector3(MAP_TOP_LEFT.x + i * MAP_TILE_SIZE, MAP_TOP_LEFT.y - j * MAP_TILE_SIZE, 0);
		}
	}

	for (int j = 0; j < MAP_HEIGHT; ++j) {
		for (int i = 0; i < MAP_WIDTH; ++i) {
			
			n[j * MAP_WIDTH + i].N = (validTile((j - 1) * MAP_WIDTH + (i + 0)) ? &n[(j - 1) * MAP_WIDTH + (i + 0)] : nullptr);
			n[j * MAP_WIDTH + i].NE = (validTile((j - 1) * MAP_WIDTH + (i + 1)) ? &n[(j - 1) * MAP_WIDTH + (i + 1)] : nullptr);
			n[j * MAP_WIDTH + i].E = (validTile((j + 0) * MAP_WIDTH + (i + 1)) ? &n[(j + 0) * MAP_WIDTH + (i + 1)] : nullptr);
			n[j * MAP_WIDTH + i].SE = (validTile((j + 1) * MAP_WIDTH + (i + 1)) ? &n[(j + 1) * MAP_WIDTH + (i + 1)] : nullptr);
			n[j * MAP_WIDTH + i].S = (validTile((j + 1) * MAP_WIDTH + (i + 0)) ? &n[(j + 1) * MAP_WIDTH + (i + 0)] : nullptr);
			n[j * MAP_WIDTH + i].SW = (validTile((j + 1) * MAP_WIDTH + (i - 1)) ? &n[(j + 1) * MAP_WIDTH + (i - 1)] : nullptr);
			n[j * MAP_WIDTH + i].W = (validTile((j + 0) * MAP_WIDTH + (i - 1)) ? &n[(j + 0) * MAP_WIDTH + (i - 1)] : nullptr);
			n[j * MAP_WIDTH + i].NW = (validTile((j - 1) * MAP_WIDTH + (i - 1)) ? &n[(j - 1) * MAP_WIDTH + (i - 1)] : nullptr);
			
		}
	}
}


void Map::binaryInsert(Node *n) {
	
	//Handle empty vector.
	if (v->empty()) {
		v->insert(v->begin(),n);
		return;
	}

	int LGap = (v->size()) / 2, RGap = (v->size()-1)/2;
	int index = v->size()/2;

	while (LGap + RGap > 0) {
		
		if ((v->at(index)->length + v->at(index)->distance) > (n->length + n->distance)) {
			index -= (LGap+1) / 2;
			RGap = (LGap-1) / 2;
			LGap = LGap - RGap - 1;
		}
		else {
			index += (RGap + 1) / 2;
			LGap = (RGap - 1) / 2;
			RGap = RGap - LGap - 1;
		}
	}
	
	v->insert(v->begin() + index + int((v->at(index)->length + v->at(index)->distance) < (n->length + n->distance)), n);
	
}
