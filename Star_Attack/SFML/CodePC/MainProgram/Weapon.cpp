#include "Weapon.h"



Weapon::Weapon(float timeBetweenShots):
	timeBetweenShots(timeBetweenShots)
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
