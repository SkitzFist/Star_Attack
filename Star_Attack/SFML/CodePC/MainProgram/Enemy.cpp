#include "Enemy.h"
#include "CircleState.h"


Enemy::Enemy(sf::Texture* texture, sf::Vector2f pos, ResourceManager* rm, BulletHandler* bh):
	Entity(texture, 1,1)
{
	//config

	//setup
	setPosition(pos.x/2, pos.y/2);
	currentState = new CircleState(rm, bh);

}


Enemy::~Enemy()
{
	delete currentState;
}

void Enemy::updateObject(sf::Time delta)
{
	currentState = currentState->update(delta);
}

void Enemy::moveObject()
{
}

void Enemy::takeDamage()
{
	currentState->takeDamage();
}
