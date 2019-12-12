#pragma once
#include "BulletHandler.h"
#include "Entity.h"

class Collision
{
public:
	Collision();
	~Collision();
	void checkBetween(BulletHandler* bh, Entity* entity);
	void radiusCheckBetween(BulletHandler* bh, Entity* entity);
};

