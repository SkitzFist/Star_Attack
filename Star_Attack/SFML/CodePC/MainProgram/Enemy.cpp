#include "Enemy.h"
#include "SpiralWeapon.h"


Enemy::Enemy(sf::Texture* texture, sf::Vector2f pos, ResourceManager* rm, BulletHandler* bh):
	Entity(texture)
{
	//config
	float timeBetweenShots = 0.5f;
	//setup
	setPosition(pos.x/2, pos.y/2);
	currentWeapon = new SpiralWeapon(timeBetweenShots, rm, bh);
}


Enemy::~Enemy()
{
}

void Enemy::updateObject(sf::Time delta)
{
	currentWeapon->update(delta);

	if (currentWeapon->getTimeLeft() <= 0.f) {
		currentWeapon->fire();
	}
}

void Enemy::moveObject()
{
}
