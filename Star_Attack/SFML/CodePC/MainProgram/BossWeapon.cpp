#include "BossWeapon.h"



BossWeapon::BossWeapon(float timeBetweenShots, ResourceManager* rm, BulletHandler* bh):
	Weapon(timeBetweenShots, rm, bh)
{
	timeLeft = 0;
}


BossWeapon::~BossWeapon()
{
}

int BossWeapon::getNrOfAngles() const
{
	return nrOfAngles;
}

void BossWeapon::fire(sf::Vector2f pos)
{
	fireBoss(pos);
}
