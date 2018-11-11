#pragma once

#include "Vector3.h"

struct CollisionData {
	Vector3 normal;
	float dist;
};

class CollisionShape
{
public:

	float mass = INFINITY;
	Vector3 position;

	CollisionShape(float m, Vector3 pos) { 
		mass = m;
		position = pos;
	}

	virtual bool collidedWith(CollisionShape *s, CollisionData &d) = 0;

	virtual ~CollisionShape();
};

