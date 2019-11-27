#include "PlayerWeapon.h"



PlayerWeapon::PlayerWeapon(float timeBetweenShots):
	Weapon(timeBetweenShots)
{
	timeLeft = 0;
}


PlayerWeapon::~PlayerWeapon()
{
}

void PlayerWeapon::update(sf::Time delta)
{
	timeLeft -= delta.asSeconds();
}

void PlayerWeapon::fire()
{
	timeLeft = getTimeBetweenShots();
}
