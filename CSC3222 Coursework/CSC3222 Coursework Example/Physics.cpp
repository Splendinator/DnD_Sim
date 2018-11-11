#include "Physics.h"



Physics::Physics()
{

	
	//numRaiders = 0;
	

	//for (int i = 0; i < numRaiders; i++)
	//{
	//	Entity temp;
	//
	//	temp.getPhysicsNode().updatePosition(Vector3(-311 + 27 * i, -80.0f, -199.9f));
	//	temp.getPhysicsNode().updateRotation(i*20.0f);
	//	temp.getPhysicsNode().updateScale(Vector3(10.0f, 10.0f, 1.0f));
	//
	//	raiders.push_back(temp);
	//}

	map.position = Vector3(0.0f, 100.0f, -200.0f);
	map.rotation = 0.0f;
	map.scale = Vector3(864.0f, 540.0f, 100.0f);



	dragon.getPhysicsNode().updatePosition(Vector3(-300.0f, 90.0f, -199.5f));
	dragon.getPhysicsNode().updateRotation(225.f);
	dragon.getPhysicsNode().updateScale(Vector3(50.0f, 50.0f, 1.0f));
	dragon.getPhysicsNode().terminalVelocity = 0.012f;
	dragon.aggroRange = 150;
	dragon.getPhysicsNode().rad = 50.f;
	dragon.getPhysicsNode().mass = 1.0f;
	dragon.maxHealth = 1000;
	dragon.health = 1000;

	dragonState = 1;

	breath.position = Vector3(-24.0f, 16.0f, -0.05f);
	breath.rotation = 180;
	breath.scale = Vector3(2.0f, 1.0f, 1.0f);

	breathState = 1;


	
	//Boulders
	terrainColliders.push_back(new CollisionCircle(INFINITY, Vector3(149, 39, 0), 22));
	terrainColliders.push_back(new CollisionCircle(INFINITY, Vector3(500, 365, 0), 29));
	terrainColliders.push_back(new CollisionCircle(INFINITY, Vector3(104, 362, 0), 39));
	terrainColliders.push_back(new CollisionCircle(INFINITY, Vector3 (-80, 260, 0), 39));
	terrainColliders.push_back(new CollisionCircle(INFINITY, Vector3(-80, 260, 0), 39));
	terrainColliders.push_back(new CollisionCircle(INFINITY, Vector3(-166, -282, 0), 14));
	terrainColliders.push_back(new CollisionCircle(INFINITY, Vector3(-285, -325, 0), 18));
	terrainColliders.push_back(new CollisionCircle(INFINITY, Vector3(-246, -343, 0), 11));
	terrainColliders.push_back(new CollisionCircle(INFINITY, Vector3(-575, -78, 0), 42));
	terrainColliders.push_back(new CollisionCircle(INFINITY, Vector3(-540, 196, 0), 37));


	//Walls
	terrainColliders.push_back(new CollisionSquare(INFINITY, Vector3(240, -250, 0),180,20,145));
	terrainColliders.push_back(new CollisionSquare(INFINITY, Vector3(220, -60, 0), 106, 40, 80));
	terrainColliders.push_back(new CollisionSquare(INFINITY, Vector3(520, -60, 0), 200, 40, 90));
	terrainColliders.push_back(new CollisionSquare(INFINITY, Vector3(655, 100, 0), 200, 40, 185));
	terrainColliders.push_back(new CollisionSquare(INFINITY, Vector3(570, 400, 0), 200, 40, 140));
	terrainColliders.push_back(new CollisionCircle(INFINITY, Vector3(448, 461, 0),60));
	terrainColliders.push_back(new CollisionSquare(INFINITY, Vector3(218, 451, 0), 200, 40, 75));
	terrainColliders.push_back(new CollisionSquare(INFINITY, Vector3(-79, 341, 0), 200, 40, 60));
	terrainColliders.push_back(new CollisionSquare(INFINITY, Vector3(-292, 268, 0), 70, 20, 95));
	terrainColliders.push_back(new CollisionSquare(INFINITY, Vector3(10, 470, 0), 70, 20, 205));
	terrainColliders.push_back(new CollisionSquare(INFINITY, Vector3(-37, 568, 0), 140, 30, 115));
	terrainColliders.push_back(new CollisionSquare(INFINITY, Vector3(-261, 585, 0), 140, 30, 80));
	terrainColliders.push_back(new CollisionSquare(INFINITY, Vector3(-453, 465, 0), 100, 120, 10));
	terrainColliders.push_back(new CollisionCircle(INFINITY, Vector3(-323, 408, 0), 60));
	terrainColliders.push_back(new CollisionCircle(INFINITY, Vector3(-258, 387, 0), 20));
	terrainColliders.push_back(new CollisionCircle(INFINITY, Vector3(-545, 357, 0), 30));
	terrainColliders.push_back(new CollisionSquare(INFINITY, Vector3(-609, 200, 0), 194, 30, 15));
	terrainColliders.push_back(new CollisionSquare(INFINITY, Vector3(-593, -180, 0), 240, 30, 145));
	terrainColliders.push_back(new CollisionSquare(INFINITY, Vector3(-405, -336, 0), 240, 30, 125));
	terrainColliders.push_back(new CollisionSquare(INFINITY, Vector3(63, -402, 0), 540, 30, 90));
	terrainColliders.push_back(new CollisionCircle(INFINITY, Vector3(-63, -382, 0), 60));

	wallColliders.push_back(new CollisionSquare(INFINITY, Vector3(240, -250, 0), 180, 20, 145));
	wallColliders.push_back(new CollisionSquare(INFINITY, Vector3(220, -60, 0), 106, 40, 80));
	wallColliders.push_back(new CollisionSquare(INFINITY, Vector3(520, -60, 0), 200, 40, 90));
	wallColliders.push_back(new CollisionSquare(INFINITY, Vector3(655, 100, 0), 200, 40, 185));
	wallColliders.push_back(new CollisionSquare(INFINITY, Vector3(570, 400, 0), 200, 40, 140));
	wallColliders.push_back(new CollisionCircle(INFINITY, Vector3(448, 461, 0), 60));
	wallColliders.push_back(new CollisionSquare(INFINITY, Vector3(218, 451, 0), 200, 40, 75));
	wallColliders.push_back(new CollisionSquare(INFINITY, Vector3(-79, 341, 0), 200, 40, 60));
	wallColliders.push_back(new CollisionSquare(INFINITY, Vector3(-292, 268, 0), 70, 20, 95));
	wallColliders.push_back(new CollisionSquare(INFINITY, Vector3(10, 470, 0), 70, 20, 205));
	wallColliders.push_back(new CollisionSquare(INFINITY, Vector3(-37, 568, 0), 140, 30, 115));
	wallColliders.push_back(new CollisionSquare(INFINITY, Vector3(-261, 585, 0), 140, 30, 80));
	wallColliders.push_back(new CollisionSquare(INFINITY, Vector3(-453, 465, 0), 100, 120, 10));
	wallColliders.push_back(new CollisionCircle(INFINITY, Vector3(-323, 408, 0), 60));
	wallColliders.push_back(new CollisionCircle(INFINITY, Vector3(-258, 387, 0), 20));
	wallColliders.push_back(new CollisionCircle(INFINITY, Vector3(-545, 357, 0), 30));
	wallColliders.push_back(new CollisionSquare(INFINITY, Vector3(-609, 200, 0), 194, 30, 15));
	wallColliders.push_back(new CollisionSquare(INFINITY, Vector3(-593, -180, 0), 240, 30, 145));
	wallColliders.push_back(new CollisionSquare(INFINITY, Vector3(-405, -336, 0), 240, 30, 125));
	wallColliders.push_back(new CollisionSquare(INFINITY, Vector3(63, -402, 0), 540, 30, 90));
	wallColliders.push_back(new CollisionCircle(INFINITY, Vector3(-63, -382, 0), 60));

	//Rubble
	rubbleColliders.push_back(new CollisionSquare(INFINITY, Vector3(500, -20, 0), 40, 100, 0));
	rubbleColliders.push_back(new CollisionSquare(INFINITY, Vector3(570, 200, 0), 180, 70, 170));
	rubbleColliders.push_back(new CollisionCircle(INFINITY, Vector3(256, 117, 0), 30));
	rubbleColliders.push_back(new CollisionCircle(INFINITY, Vector3(310, 344, 0), 95));
	rubbleColliders.push_back(new CollisionCircle(INFINITY, Vector3(145, 185, 0), 45));
	rubbleColliders.push_back(new CollisionCircle(INFINITY, Vector3(224, 236, 0), 30));
	rubbleColliders.push_back(new CollisionCircle(INFINITY, Vector3(86, 230, 0), 25));
	rubbleColliders.push_back(new CollisionCircle(INFINITY, Vector3(-30, 253, 0), 60));
	rubbleColliders.push_back(new CollisionCircle(INFINITY, Vector3(-5, 126, 0), 30));
	rubbleColliders.push_back(new CollisionSquare(INFINITY, Vector3(-224, 112, 0), 150, 70, 50));
	rubbleColliders.push_back(new CollisionCircle(INFINITY, Vector3(-439, -59, 0), 60));
	rubbleColliders.push_back(new CollisionCircle(INFINITY, Vector3(-442, -169, 0), 40));
	rubbleColliders.push_back(new CollisionCircle(INFINITY, Vector3(-439, -59, 0), 60));
	rubbleColliders.push_back(new CollisionCircle(INFINITY, Vector3(-442, -169, 0), 40));
	rubbleColliders.push_back(new CollisionCircle(INFINITY, Vector3(-289, 539, 0), 73));
	rubbleColliders.push_back(new CollisionCircle(INFINITY, Vector3(-247, -41, 0), 30));


	vector<CollisionShape *> empty;

	cout << endl << "******* Raider Map ********" << endl;
	raiderMap = new Map(10, &terrainColliders, &rubbleColliders);

	cout << endl << "******* Heal Map (no rubble) ********" << endl;
	healMap = new Map(10, &terrainColliders, &empty);

	cout << endl << "******* Dragon Map ********" << endl;
	dragonMap = new Map(30, &terrainColliders, &empty);




	//terrainColliders.push_back(new CollisionCircle(INFINITY, Vector3(224, 236, 0), 30));
}

Physics::~Physics()
{
	raiders.clear();
}



void Physics::UpdatePhysics(float msec)
{

	/* Placeholder functionality to show things moving on screen
	Note that our physics update is parcelled away from our renderer. So
	long as our SceneNode has a pointer to its associated PhysicsData it
	should update reliably. Note that as these pointers are set at the
	beginning of execution, we should take care when messing around with
	the contents of our raiders <vector> */
	
	//float shift;

	//shift = 0.3*msec;

	/* Here, we simply rotate each raider counter-clockwise by a value
	relative to framerate. */

	/* This segment demonstrates a simple finite state machine. State 1 is
	analogous to 'move right'. Once the dragon has moved right beyond a
	specific threshold (in this example, 100 units from origin), it flips
	to State 0, 'move left', and continues until it is -320 units from
	origin. Repeat ad nauseum. You should compartmentalise this decision
	making away from your physics system - it is included here for
	illustrative purposes only.	*/

	//shift = 0.1*msec;

	//if (dragon.getPhysicsNode().getPosition().x > 100.0f)
	//{
	//	dragonState = 0;
	//}
	//else if(dragon.getPhysicsNode().getPosition().x < -320.0f)
	//{
	//	dragonState = 1;
	//}

	//if (dragonState == 1)
	//{
	//	dragon.getPhysicsNode().move(Vector3(shift,0,0));
	//}
	//else
	//{
	//	dragon.getPhysicsNode().move(Vector3(-shift, 0, 0));
	//}

	/* Note also, as highlighted in the comments in Renderer.cpp, that
	we do not explicitly change the position of the fiery breath - but
	the breath moves in any case. This is because it inherits its base
	coordinates from its parent (the dragon) in our scene structure. It
	also inherits its orientation from the dragon - to see this in
	action, uncomment the line of code below: */

	//dragon.rotation -= shift;

	/* Lastly, there may be times when we want to control the scale of
	an object. If that object collides, it makes sense for its physics
	data to be aware of, or govern, this change in scale. Our SceneNode
	is adapted to read in an object's scale each frame from its associated
	PhysicsData just in case it has changed - here is an example of that
	applied to the dragon's breath weapon. */

	//if (breath.scale.x > 100.0f)
	//{
	//	breathState = 0;
	//	breath.scale.x = 100;
	//	breath.scale.y = 50;
	//}
	//else if (breath.scale.x < 2.0f)
	//{
	//	breathState = 1;
	//	breath.scale.x = 2.0f;
	//	breath.scale.y = 1.0f;
	//}

	//if (breathState == 1)
	//{
	//	breath.scale.x += 1.5*shift;
	//	breath.scale.y += 0.75*shift;
	//}
	//else
	//{
	//	breath.scale.x -= 2*shift;
	//	breath.scale.y -= shift

	//if (!leader) {
	//	cout << "Hi";
	//}

	if (leader) {
		dragon.state = HUNTING;
		leader->getPhysicsNode().terminalVelocity = (onRubble(*leader) ? 0.008f : 0.020f);
		update(*leader, msec);
		handleCollisions(*leader, msec);
		handleRaiderCollisions(*leader, msec);
		handleFireCollision(*leader, msec);
		if (leader->health < 0) {
			leader = nullptr;
		}
	}

	r:
	for (vector<EntityRaider>::iterator i = raiders.begin(); i != raiders.end(); ++i) {
		i->getPhysicsNode().terminalVelocity = (onRubble(*i) ? 0.008f : 0.02f);
		i->getPhysicsNode().lookAt(dragon.getPhysicsNode().getPosition());
		handleCollisions(*i,msec);
		handleRaiderCollisions(*i, msec);
		handleRaiderAI(*((EntityRaider *)(&*i)), msec);
		handleFireCollision(*i, msec);
		update(*i, msec);
		if (i->health < 0 || (i->state == RETREAT && i->getPhysicsNode().getPosition().y < -350)) {
			raiders.erase(i);
			goto r;
		}
	}

	a:
	for (vector<EntityArrow>::iterator i = arrows.begin(); i != arrows.end(); ++i) {
		i->lifetime += msec;
		handleArrow(*i, msec);
		if (i->lifetime > 2000) {
			arrows.erase(i);
			goto a;
		}

	}
	
	handleDragonAI(dragon, msec);
	update(dragon, msec);
	handleCollisions(dragon, msec);
	handleRaiderCollisions(dragon, msec);





}

void Physics::update(Entity &e, float msec)
{
	e.getPhysicsNode().velocity = (e.getPhysicsNode().velocity + e.getPhysicsNode().acceleration * msec);
	e.getPhysicsNode().velocity = (e.getPhysicsNode().velocity * powf(0.998, msec));
	if (e.getPhysicsNode().velocity.Length() > e.getPhysicsNode().terminalVelocity) {
		e.getPhysicsNode().velocity = (e.getPhysicsNode().velocity * (e.getPhysicsNode().terminalVelocity / e.getPhysicsNode().velocity.Length()));
	}
	e.getPhysicsNode().updatePosition(e.getPhysicsNode().getPosition() + e.getPhysicsNode().velocity * msec);
	


}

void Physics::handleCollisions(Entity &e, float msec)
{
	for (vector<CollisionShape *>::iterator i = terrainColliders.begin(); i != terrainColliders.end(); ++i) {
		if (e.getPhysicsNode().getCollisionShape().collidedWith(*i, cd)) {
			e.getPhysicsNode().move(cd.normal * cd.dist);
		}
	}
}

void Physics::handleRaiderCollisions(Entity &e, float msec)
{
	for (vector<EntityRaider>::iterator i = raiders.begin(); i != raiders.end(); ++i) {
		if (e.getPhysicsNode().getCollisionShape().collidedWith(&i->getPhysicsNode().getCollisionShape(), cd)) {
			float totalMass = e.getPhysicsNode().mass + i->getPhysicsNode().mass;
			e.getPhysicsNode().move(cd.normal * cd.dist * i->getPhysicsNode().mass / totalMass);
			i->getPhysicsNode().move(-cd.normal * cd.dist * e.getPhysicsNode().mass / totalMass);
		}
	}
}

bool Physics::onRubble(Entity &e)
{
	for (vector<CollisionShape *>::iterator i = rubbleColliders.begin(); i != rubbleColliders.end(); ++i) {
		if (e.getPhysicsNode().getCollisionShape().collidedWith(*i, cd)) {
			return true;
		}
	}
	return false;
}



void Physics::handleRaiderAI(EntityRaider &e, float msec)
{
	e.fireTime += msec;

	if (!leader) {
		e.state = RETREAT;
	}

	//cout << e.state << endl;

	bool recalc = false;
	e.pathTimer += msec;
	if (e.pathTimer > RE_PATH_TIME) {
		e.pathTimer -= RE_PATH_TIME;
		recalc = true;
	}

	if (e.state == FOLLOW && recalc) {

		e.moves.clear();

		Vector3 t = e.getPhysicsNode().getPosition() - leader->getPhysicsNode().getPosition();
		t.Normalise();

		t = leader->getPhysicsNode().getPosition() + t * FOLLOW_CLOSENESS;
		t = t + Vector3(rand() % FOLLOW_RAND, rand() % FOLLOW_RAND, 0);

		raiderMap->genRoute(e, leader->getPhysicsNode().getPosition());
	
	}

	if (e.state == HEAL) {
		if ((e.getPhysicsNode().getPosition() - Vector3(444, 100, 0)).Length() < 70.f) {
			e.health += min(e.maxHealth - e.health, 50);
			e.state = FOLLOW;
			e.pathTimer = RE_PATH_TIME;
		}

	}

	if (e.state == HOARD) {
		if ((e.getPhysicsNode().getPosition() - Vector3(-146, 513, 0)).Length() < 70.f) {
			e.arrowDamage = 15.f;
			e.state = FOLLOW;
			e.pathTimer = RE_PATH_TIME;
		}

	}

	if (e.state == RETREAT && recalc) {
		e.moves.clear();
		raiderMap->genRoute(e, Vector3(120, -380, 0));
	}


	//FOLLOW MOVEMENT INSTRUCTION LIST
	if (!e.moves.empty())
	{
		Vector3 direction = e.moves.at(0) - e.getPhysicsNode().getPosition();
		direction.Normalise();
		e.getPhysicsNode().acceleration = direction * 0.0005f * msec;

		if ((e.moves.at(0) - e.getPhysicsNode().getPosition()).Length() < 20.f) e.moves.erase(e.moves.begin());

	}


	
}

void Physics::handleDragonAI(EntityDragon &e, float msec) {
	
	if (e.state == HUNTING) {

		Entity *en = &e;
		float distance = INFINITY;
		float f;
		//Find closest unit
		for (vector<EntityRaider>::iterator it = raiders.begin(); it != raiders.end(); ++it) {
			f = (it->getPhysicsNode().getPosition() - e.getPhysicsNode().getPosition()).Length();
			if (f < distance) {
				distance = f;
				en = &*it;
			}
		}



		if (distance > e.aggroRange) {
			e.breathState = NONE;
			if (leader) {
				en = leader; //If leader is alive and no one is in range then hunt leader
				distance = (leader->getPhysicsNode().getPosition() - e.getPhysicsNode().getPosition()).Length();
			}
		}


		if (distance < e.aggroRange) {
			e.breathState = GROWING;
		}
		else
		{
			e.breathState = NONE;
			breath.scale.x = breath.scale.y = 0;
		}

		if (e.breathState < 2) {	//If attacking
			
			float shift = msec * 0.03f;

			if (breath.scale.x > 150.f) breathState = SHRINKING;
			if (breath.scale.x < 0.f) breathState = GROWING;

			if (breathState == SHRINKING) shift = -shift;

			breath.scale.x += shift;
			breath.scale.y += shift/2;
			breath.rotation = 360 - (getAngle(en->getPhysicsNode().getPosition() - (e.getPhysicsNode().getPosition() + breath.position))) + 90;
			if (breath.rotation > 360.f) breath.rotation -= 360.f;



		}
		dragon.pathTimer += msec;

		if (e.pathTimer > RE_PATH_TIME) {
			e.moves.clear();
			dragonMap->genRoute(e, en->getPhysicsNode().getPosition());
			e.pathTimer -= RE_PATH_TIME;
		}

		//FOLLOW MOVEMENT INSTRUCTION LIST
		if (!e.moves.empty())
		{
			Vector3 direction = e.moves.at(0) - e.getPhysicsNode().getPosition();
			direction.Normalise();
			e.getPhysicsNode().acceleration = direction * 0.0005f * msec;

			if ((e.moves.at(0) - e.getPhysicsNode().getPosition()).Length() < 20.f) e.moves.erase(e.moves.begin());

		}
		

		
	}
}

float Physics::getAngle(Vector3 v) {
	
	float ans = RadToDeg(atan(v.x / v.y));

	if (v.y < 0) ans += 180;

	if (ans < 0) ans += 360.f;

	return ans;
}

void Physics::handleFireCollision(Entity &e, float msec) {
	Vector3 ve = dragon.getPhysicsNode().getPosition() + breath.position;
	ve.z = 0;
	CollisionCircle c(INFINITY, ve, breath.scale.x );

	if (e.getPhysicsNode().getCollisionShape().collidedWith(&c, cd)) {

		float rot = (360 - breath.rotation);
		rot += 90;
		if (rot > 360.f) rot -= 360.f;

		float b1 = rot - 20;
		float b2 = rot + 20;

		if (b1 < 0) b1 += 360;
		if (b2 < 0) b2 += 360;

		float angle = getAngle(cd.normal);

		//cout << b1 << " " << b2 << " " << angle << " " << rot << endl;
		
		if (b1 > b2) {
			if (angle < 180) b1 -= 360;
			else			 b2 += 360;
		}
		
		if (angle > b1 && angle < b2) {
			e.health -= 50 * msec / 1000;
		}

	}
}

void Physics::handleArrow(EntityArrow &e, float msec) {

	e.getPhysicsNode().updatePosition(e.getPhysicsNode().getPosition() + e.getPhysicsNode().velocity * msec);

	for (vector<CollisionShape *>::iterator i = wallColliders.begin(); i != wallColliders.end(); ++i) {
		if (e.getPhysicsNode().getCollisionShape().collidedWith(*i, cd)) {
			e.damage = 0;
			e.getPhysicsNode().velocity = Vector3(0, 0, 0);
		}
	}

	if (dragon.getPhysicsNode().getCollisionShape().collidedWith(&e.getHurtBox(),cd)) {
		dragon.health -= e.damage;
		e.lifetime = 60000;
	}






}

