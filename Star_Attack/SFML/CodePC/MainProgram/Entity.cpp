#include "Entity.h"



Entity::Entity(sf::Texture* texture):
	GameObject(texture)
{
	isAlive = true;
}


Entity::~Entity()
{
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
	moveObject();
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
