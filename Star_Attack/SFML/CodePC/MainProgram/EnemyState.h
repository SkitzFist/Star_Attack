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

	//Enemy* getEnemy() const;

protected:
	BossWeapon* currentWeapon;
	ResourceManager* rm;
	BulletHandler* bh;
private:

	//Enemy* enemy;
};

