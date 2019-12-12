#pragma once
#include "BossWeapon.h"
class CircleWeapon :
	public BossWeapon
{
public:
	CircleWeapon(float timeBetweenShots, ResourceManager* rm, BulletHandler* bh, bool isSpiral = false);
	virtual ~CircleWeapon();

	void updateRotation(sf::Vector2f pos);

	// Inherited via BossWeapon
	virtual void Setup(sf::Vector2f pos, int nrOfAngles) override;
	virtual void fireBoss(sf::Vector2f pos) override;

private:
	int index;
	float radius;
	float offset;
	float rotationSpeed;
	bool isSpiral;
};

