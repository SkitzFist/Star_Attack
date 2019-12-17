#pragma once
#include "BossWeapon.h"
#include "BulletHandler.h"
#include "ResourceManager.h"

class EnemyState
{
public:
	EnemyState(ResourceManager* rm, BulletHandler* bh);
	virtual ~EnemyState();
	
	virtual EnemyState* update(sf::Time delta) = 0;
	virtual void fire() = 0;
	virtual void takeDamage() = 0;

protected:
	BossWeapon* currentWeapon;
	ResourceManager* rm;
	BulletHandler* bh;
	int health;
};

