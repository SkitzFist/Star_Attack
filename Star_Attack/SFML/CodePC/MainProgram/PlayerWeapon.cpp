#include "PlayerWeapon.h"



PlayerWeapon::PlayerWeapon(float timeBetweenShots, ResourceManager* rm, BulletHandler* bh):
	Weapon(timeBetweenShots, rm, bh)
{
	timeLeft = 0;
}


PlayerWeapon::~PlayerWeapon()
{
}

void PlayerWeapon::fire(sf::Vector2f startPos, sf::Vector2f dir)
{
	Bullet* bullet = new Bullet(rm->getWhiteBallTexture());
	bullet->setPosition(startPos.x, startPos.y);
	bullet->setup(dir);
	bh->addBullet(bullet);

	timeLeft = getTimeBetweenShots();
}

void PlayerWeapon::fire()
{
}
