#include "Entity.h"



Entity::Entity(sf::Texture* texture, int spriteRows, int spriteColumns):
	GameObject(texture, spriteRows, spriteColumns)
{
	isAlive = true;
}


Entity::~Entity()
{
	delete animator;
}

bool Entity::getIsAlive() const
{
	return isAlive;
}

void Entity::update(sf::Time delta)
{
	updateObject(delta);
}

void Entity::move()
{
	//moveObject();
}

void Entity::setIsAlive(bool isAlive)
{
	this->isAlive = isAlive;
}

int Entity::getHealth() const
{
	return health;
}

void Entity::addToHealth(int value)
{
	health += value;
}
