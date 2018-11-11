#pragma once
#include "EntityAI.h"

enum DRAGONSTATES { WAITING, HUNTING };

enum BREATHSTATES { GROWING, SHRINKING, NONE};

class EntityDragon :
	public EntityAI
{
public:

	float aggroRange;
	int breathState;


	EntityDragon();
	~EntityDragon();
};

 