#pragma once
#include "Entity.h"
class EntityArrow :
	public Entity
{
public:

	float damage;
	float lifetime = 0;

	CollisionSquare getHurtBox() {

		return CollisionSquare(5,p.getPosition(),p.getScale().x, p.getScale().y,p.getRotation());
	}

	EntityArrow();
	~EntityArrow();
};

