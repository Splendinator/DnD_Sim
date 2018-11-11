#pragma once
#include "CollisionShape.h"
#include "Matrix4.h"

class CollisionSquare
	: public CollisionShape
{
public:

	float height, width, angle;

	CollisionSquare(float m, Vector3 pos, float h, float w, float a) : CollisionShape(m, pos) {

		height = h;
		width = w;
		angle = a;
	};
	~CollisionSquare();

	bool collidedWith(CollisionShape *s, CollisionData &d);
};

