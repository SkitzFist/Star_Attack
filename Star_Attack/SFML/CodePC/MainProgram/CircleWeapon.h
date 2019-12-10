#pragma once
#include "BossWeapon.h"
class CircleWeapon :
	public BossWeapon
{
public:
	CircleWeapon(float timeBetweenShots, ResourceManager* rm, BulletHandler* bh);
	virtual ~CircleWeapon();

	// Inherited via BossWeapon
	virtual void Setup(sf::Vector2f pos, int nrOfAngles) override;

	// Inherited via BossWeapon
	virtual void fireBoss(sf::Vector2f pos) override;

private:
	int index;
	float radius;
};

