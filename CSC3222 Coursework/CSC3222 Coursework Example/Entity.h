#pragma once
#include "PhysicsNode.h"

class Entity
{

protected:
	PhysicsNode p;
	

public:
	Entity();
	~Entity();

	float health;
	float maxHealth;

	//Entity operator=(Entity e) {
	//	p = e.getPhysicsNode();
	//	return *this;
	//}

	//Entity(const Entity &o) { std::cout << "COPYING" << std::endl; }

	PhysicsNode &getPhysicsNode() { return p; }

};

