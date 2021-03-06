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

void Weapon::update(sf::Time delta)
{
	timeLeft -= delta.asSeconds();
}

float Weapon::getTimeLeft() const
{
	return timeLeft;
}

void Weapon::setTimeBetweenShots(float value)
{
	timeBetweenShots = value;
}

float Weapon::getTimeBetweenShots() const
{
	return timeBetweenShots;
}