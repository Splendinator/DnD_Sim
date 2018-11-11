#pragma once
#include <vector>
#include "Entity.h"
#include "Vector3.h"

class EntityAI
	: public Entity
{

private:
	



public:

	std::vector<Vector3> moves;	//List of coordinates to move to
	int state = 0;
	float pathTimer = 0;		//Timer for use with how often the unit recalculates path.

	EntityAI();
	~EntityAI();
};

