#pragma once
#include "Vector3.h" 
#include "common.h"
#include "Vector2.h"
#include "CollisionShape.h"
#include "CollisionCircle.h"
#include <vector>

struct PhysicsD {
	Vector3 position;
	float rotation;
	Vector3 scale;
};



class PhysicsNode
{
private:
	PhysicsD *p;

	float GRID_SIZE = 26.55;


public:




	Vector3 acceleration;
	Vector3 velocity;
	float terminalVelocity;
	float rad;
	float mass;

	PhysicsNode();
	PhysicsNode(const PhysicsNode &p);
	~PhysicsNode();

	//PhysicsNode operator=(PhysicsNode pn) {
	//	p.position = pn.p.position;
	//	p.rotation = pn.p.rotation;
	//	p.scale = pn.p.scale;
	//	acceleration = pn.acceleration;
	//	velocity = pn.velocity;
	//	terminalVelocity = pn.terminalVelocity;
	//	return *this;
	//}

	void updatePosition(Vector3 v)	{ p->position = v; }
	void updatePosition(int x, int y) { p->position = Vector3(-676.6 + 26.55 * x, 583.65 - 26.55 * y , 0); }
	void updateScale(Vector3 v)		{ p->scale = v; }
	void updateRotation(float r) { p->rotation =  -r-135; } //Magic numbers make rotation happen CLOCKWIZE starting at NORTH = 0;

	void lookAt(Vector3);

	Vector3 getPosition()		const	{ return p->position; }
	Vector3 getScale()			const	{ return p->scale; }
	float	getRotation()		const	{ return -p->rotation - 135; } 
	PhysicsD * getPhysicsData() const	{ return p; }
	 
	CollisionCircle getCollisionShape() { return CollisionCircle(mass,p->position,rad); }


	//Return which grid the entity is in. (0,0) top left.
	Vector2 getCoords() { return Vector2(int(-663.325f - p->position.x / 26.55f), int(596.925 - p->position.y / 26.55)); }
	

	//Vector3 dependent on rotation, always faces foward.
	Vector3 foward() {
		float r = -(p->rotation + 135);
		Vector3 v = Vector3(sin(DegToRad(r)), cos(DegToRad(r)), 0);
		v.Normalise();
		return v;
	}

	

	void move(Vector3 v) { p->position += v; }
	void rotate(float r) { p->rotation += r; }



};

