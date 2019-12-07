#include "Weapon.h"



Weapon::Weapon(float timeBetweenShots, ResourceManager* rm, BulletHandler* bh):
	timeBetweenShots(timeBetweenShots),
	rm(rm),
	bh(bh)
{
}


Weapon::~Weapon()
{
}

float Weapon::getTimeLeft() const
{
	return timeLeft;
}

float Weapon::getTimeBetweenShots() const
{
	return timeBetweenShots;
}