#include "Enemy.h"



Enemy::Enemy(sf::Texture* texture, float x, float y):
	Entity(texture)
{
	setPosition(x / 2, y / 2);
}


Enemy::~Enemy()
{
}

void Enemy::updateObject(sf::Time delta)
{
}

void Enemy::moveObject()
{
}
