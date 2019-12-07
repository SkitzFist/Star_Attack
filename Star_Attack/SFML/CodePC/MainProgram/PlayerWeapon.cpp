#include "PlayerWeapon.h"



PlayerWeapon::PlayerWeapon(float timeBetweenShots, ResourceManager* rm, BulletHandler* bh):
	Weapon(timeBetweenShots, rm, bh)
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

void PlayerWeapon::fire(sf::Vector2f startPos, sf::Vector2f dir)
{
	Bullet* bullet = new Bullet(rm->getBossTexture());
	bullet->setPosition(startPos.x, startPos.y);
	bullet->setup(dir);
	bh->addBullet(bullet);

	timeLeft = getTimeBetweenShots();
}
