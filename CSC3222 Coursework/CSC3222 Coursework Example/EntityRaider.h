#pragma once
#include "EntityAI.h"


enum state { FOLLOW, HOARD, HEAL, RETREAT };


class EntityRaider :
	public EntityAI
{
public:

	float arrowDamage = 10.f;
	float fireTime = 0.f;
	float reloadSpeed = 6000.f;

	EntityRaider();
	~EntityRaider();
};

