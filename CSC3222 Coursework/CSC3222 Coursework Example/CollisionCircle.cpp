#include "CollisionCircle.h"
#include "Matrix4.h"




CollisionCircle::~CollisionCircle()
{
}

bool CollisionCircle::collidedWith(CollisionShape *s, CollisionData &d) {
	
	//Circle - Circle
	if (typeid(*s) == typeid(CollisionCircle)) {
		CollisionCircle *o = (CollisionCircle *)s;
		Vector3 v = position - o->position;
		if (v.Length() < radius + o->radius) {
			d.normal = v;
			d.normal.Normalise();
			d.dist = (radius + o->radius - v.Length())/2;
			return true;
		}
		return false;
	}

	//Circle - Square
	if (typeid(*s) == typeid(CollisionSquare)) {

		CollisionSquare *o = (CollisionSquare *)s;

		Vector3 spos = o->position;
		Vector3 cpos = position;

		//Make things relative to origin since we rotate.
		cpos -= spos;
		spos = Vector3(0,0,0);
		

		//Make circle relative to foward facing square.
		Vector3 circleOrigin = cpos - spos;
		circleOrigin = Matrix4::Rotation(o->angle, Vector3(0,0,1)) * circleOrigin;

		//Closest point to circle centre;
		Vector3 closestPoint = Vector3(min(max(circleOrigin.x, spos.x-o->width), spos.x + o->width), min(max(circleOrigin.y, spos.y-o->height), spos.y + o->height),0);
		if ((closestPoint - circleOrigin).Length() < radius) {

			//Calculate normal, NOTE: WILL RETURN Vector3(0,0,0) *** IF CIRCLE IN INSIDE CUBE, DON'T USE SMALL CIRCLES OR LARGE DELTA TIME. ***
			d.normal = Vector3(min(circleOrigin.x - (spos.x - o->width), 0) + max(circleOrigin.x - (spos.x + o->width),0), min(circleOrigin.y - (spos.y - o->height),0) + max(circleOrigin.y - (spos.y + o->height), 0), 0);
			
			//d.normal = d.normal + Vector3(min(circleOrigin.x - (spos.x - o->width),0),0,0);
			//d.normal = d.normal + Vector3(max(circleOrigin.x - (spos.x + o->width),0),0,0);
			//d.normal = d.normal + Vector3(0, min(circleOrigin.y - (spos.y - o->height), 0), 0);
			//d.normal = d.normal + Vector3(0, max(circleOrigin.y - (spos.y + o->height), 0), 0);
			
			//Crude way of handling circle being inside cube.
			if ((d.normal).Length() == 0) d.normal = Vector3(1, 0, 0);	

			d.normal = Matrix4::Rotation(-o->angle, Vector3(0, 0, 1)) * d.normal;
			d.normal.Normalise();

			d.dist = radius - (closestPoint - circleOrigin).Length();
			return true;
		}

		return false;
	}

	return false;
}
