#include "Entity.h"



Entity::Entity(sf::Texture* texture):
	GameObject(texture)
{
	
}


Entity::~Entity()
{
}

void Entity::update(sf::Time delta)
{
	updateObject(delta);
}

void Entity::move()
{
	moveObject();
}
