#include "Entity.h"



Entity::Entity(sf::Texture* texture)
{
	sprite.setTexture(*texture);
}


Entity::~Entity()
{
}

void Entity::move()
{
}

void Entity::setPosition(float x, float y)
{
	sprite.setPosition(x, y);
}

void Entity::setPosition(sf::Vector2f pos)
{
	sprite.setPosition(pos);
}

void Entity::moveSprite(sf::Vector2f dir, float speed)
{
	sprite.move(dir * speed);
}

void Entity::moveSprite(float velX, float velY)
{
	sprite.move(velX , velY);
}

void Entity::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(sprite, states);
}
