#pragma once
#include <vector>
#include "Vector2.h"
#include "CollisionShape.h"
#include "CollisionCircle.h"
#include "EntityAI.h"

using namespace std;

class Map
{

	static const int MAP_WIDTH = 51;
	static const int MAP_HEIGHT = 38;
	static const int MAP_TILE_SIZE = 26.55;
	static const int RUBBLE_SPEED = 5;
	static const int SPEED = 2;
	const Vector2 MAP_TOP_LEFT = Vector2(-676.6, 583.65);

	int mapData[(MAP_WIDTH * MAP_HEIGHT)];

public:
	Map(float unitRadius, vector<CollisionShape *> *impassables, vector<CollisionShape *> *rubble);
	
	//Get tile that coordinates reside in.
	Vector2 getTile(Vector3 pos);

	//Gen route to target location for raider to follow
	void genRoute(EntityAI &e, Vector3 pos);

	~Map();

private:
	class Node {

	public:
		Node *N, *NE, *E, *SE, *S, *SW, *W, *NW;
		Node *previous; //Used for backtracking
		float length;	//Travel time from starting point
		float distance; //Distance from end node.
		float weight;	//Weight of node (5 = rubble, 2 = path)
		Vector3 pos; //Position in world.

		Map *m;	//Map this node belongs to.


		void updateNeighbors() {
				if (N) N->updateLength(length + N->weight, this);
				if (E) E->updateLength(length + E->weight, this);
				if (S) S->updateLength(length + S->weight, this);
				if (W) W->updateLength(length + W->weight, this);

				if (NE) NE->updateLength(length + NE->weight * 1.41f, this);
				if (NW) NW->updateLength(length + NW->weight * 1.41f, this);
				if (SE) SE->updateLength(length + SE->weight * 1.41f, this);
				if (SW) SW->updateLength(length + SW->weight * 1.41f, this);

		}

		void updateLength(float l, Node *p ) {
			if (length > l) {
				length = l;
				previous = p;
				m->binaryInsert(this);
			}
		}
	};

	Node n[MAP_WIDTH * MAP_HEIGHT];	//All nodes
	vector <Node *> v[MAP_WIDTH * MAP_HEIGHT]; //Nodes we are considering venturing to.

	//Node *preComputed = new Node[MAP_WIDTH * MAP_HEIGHT * MAP_WIDTH * MAP_HEIGHT];

	void initNodes();
	void binaryInsert(Node * n); //Binary insert nodes into the vector, in order of (length+distance)
	void resetNodes(); 

	inline bool validTile(int x) { return x > 0 && x < MAP_WIDTH * MAP_HEIGHT && n[x].weight > 0; };

};


