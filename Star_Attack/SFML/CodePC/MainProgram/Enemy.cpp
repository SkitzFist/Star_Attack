#include "Enemy.h"
#include "CircleWeapon.h"


Enemy::Enemy(sf::Texture* texture, sf::Vector2f pos, ResourceManager* rm, BulletHandler* bh):
	Entity(texture)
{
	//config
	float timeBetweenShots = 1.f;
	int nrOfAngles = 16;
	//setup
	setPosition(pos.x/2, pos.y/2);
	currentWeapon = new CircleWeapon(timeBetweenShots, rm, bh);
	currentWeapon->Setup(getPosition(), nrOfAngles);
}


Enemy::~Enemy()
{
}

void Enemy::updateObject(sf::Time delta)
{
	currentWeapon->update(delta);

	if (currentWeapon->getTimeLeft() <= 0.f) {
		currentWeapon->fire(getPosition());
	}
}

void Enemy::moveObject()
{
}
