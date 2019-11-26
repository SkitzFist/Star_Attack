#include "Entity.h"



Entity::Entity(sf::Texture* texture)
{
	sprite.setTexture(*texture);
	float originX = sprite.getGlobalBounds().width / 2;
	float originY = sprite.getGlobalBounds().height / 2;
	sprite.setOrigin(originX, originY);
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

void Entity::rotateSprite(float angle)
{
	static const float PI = 3.14159f;
	sprite.setRotation((angle * 180) / PI + 270.f);
}

sf::FloatRect Entity::getBounds() const
{
	return sprite.getLocalBounds();
}

sf::Vector2f Entity::getPosition() const
{
	return sprite.getPosition();
}

void Entity::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(sprite, states);
}
