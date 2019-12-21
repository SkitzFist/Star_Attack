#include "PlayerWeapon.h"
#include "normalBullet.h"


PlayerWeapon::PlayerWeapon(float timeBetweenShots, ResourceManager* rm, BulletHandler* bh):
	Weapon(timeBetweenShots, rm, bh)
{
	timeLeft = 0.f;
}


PlayerWeapon::~PlayerWeapon()
{
}

void PlayerWeapon::fire(sf::Vector2f startPos, sf::Vector2f dir)
{
	Bullet* bullet = new normalBullet(rm->getWhiteBallTexture());
	bullet->setPosition(startPos.x, startPos.y);
	bullet->setDirection(dir);
	bh->addBullet(bullet);

	timeLeft = getTimeBetweenShots();
}

void PlayerWeapon::fire(sf::Vector2f pos)
{
}

