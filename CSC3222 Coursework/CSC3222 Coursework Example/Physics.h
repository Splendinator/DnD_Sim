#pragma once

#include <vector>
#include "Vector3.h"
#include "Entity.h"
#include <math.h>
#include "CollisionShape.h"
#include "CollisionCircle.h"
#include "Map.h";
#include "EntityAI.h"
#include "EntityDragon.h"
#include "EntityRaider.h"
#include "EntityArrow.h"

using std::vector;

/* An elementary Physics Data structure, containing the bare minimum of information necessary to
say where an object should appear, and which way it should point. As we increase the complexity
of our physics system, we will add elements to this structure, but the elements which can affect
the graphical representation of entities are present below (and integrated with the graphics
framework already, to make your life easier). Ultimately, you may decide to replace this data
structure entirely (for example with a class to allow inclusion of embedded functions) but be
aware that doing so might require some slight doctoring of Renderer::Renderer() and
SceneNode::Update() */

struct PhysicsData {
	Vector3 position;
	float rotation;
	Vector3 scale;
};

/* Our placeholder physics system includes an update function, and physics data for each entity
in our environment. We also include a single integer to inform the dragon's behaviour and breath
weapon scaling.*/

class Physics {
public:

	const float RE_PATH_TIME = 2000.f;
	const float FOLLOW_CLOSENESS = 80.f;
	const int FOLLOW_RAND = 10;

	Physics();
	~Physics();

	void UpdatePhysics(float msec);


	//Leader alive/spawned?
	bool hasLeader() { return leader; }
	void addRaider(EntityRaider &t) {
		raiders.push_back(t);
		numRaiders++;
	}

	PhysicsData map;
	EntityDragon dragon;
	PhysicsData breath;
	vector<EntityRaider> raiders;
	vector<EntityArrow> arrows;
	Entity *leader;
	vector<CollisionShape *> terrainColliders;
	vector<CollisionShape *> rubbleColliders;
	vector<CollisionShape *> wallColliders;

	Map *raiderMap;
	Map *healMap;
	Map *dragonMap;

	CollisionData cd;
	
	float getAngle(Vector3 v);

private:
	void update(Entity &e, float msec);
	void handleCollisions(Entity &e, float msec);
	void handleRaiderCollisions(Entity &e, float msec);
	void handleRaiderAI(EntityRaider &e, float msec);
	void handleDragonAI(EntityDragon & e, float msec);

	void handleFireCollision(Entity & e, float msec);
	void handleArrow(EntityArrow & e, float msec);
	bool onRubble(Entity &e);
	int numRaiders;
	int	dragonState;
	int breathState;
};

