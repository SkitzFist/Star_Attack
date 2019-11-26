#include "Enemy.h"



Enemy::Enemy(sf::Texture* texture, float x, float y):
	Entity(texture)
{
	setPosition(x / 2 - getBounds().width, y / 2 - getBounds().height);
	
}


Enemy::~Enemy()
{
}

void Enemy::update(sf::Time delta)
{
}

void Enemy::move()
{
}
