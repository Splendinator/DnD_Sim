#pragma once
#include "CollisionShape.h"
#include "CollisionSquare.h"
#include "common.h"

class CollisionCircle :
	public CollisionShape
{
public:
	float radius;
	CollisionCircle(float m, Vector3 pos, float rad) : CollisionShape(m, pos) {
		radius = rad;
	};
	~CollisionCircle();
	
	bool collidedWith(CollisionShape *s, CollisionData &d);

};

