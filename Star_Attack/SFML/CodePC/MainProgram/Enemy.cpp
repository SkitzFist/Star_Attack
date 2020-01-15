#include "Enemy.h"
#include "CircleState.h"


Enemy::Enemy(sf::Texture* texture, sf::Vector2f pos, ResourceManager* rm, BulletHandler* bh):
	Entity(texture, 2,1)
{
	//config
	animator = new  Animator(getSprite(), texture, 2, 1);
	setSpriteScale(3.f);
	float startYOffset = 15.f;
	//setup
	currentState = new CircleState(rm, bh);
	animator->setAnimation(0, true);
	setPosition(pos.x / 2, (pos.y / 2) - startYOffset);

}


Enemy::~Enemy()
{
	delete currentState;
}

void Enemy::updateObject(sf::Time delta)
{
	if (currentState != nullptr) {
		currentState = currentState->update(delta);
	}
	animator->update(delta);

	if (currentState == nullptr) {
		setIsAlive(false);
	}
}

void Enemy::moveObject()
{
}

void Enemy::takeDamage()
{
	if (currentState != nullptr) {
		currentState->takeDamage();
	}


}
