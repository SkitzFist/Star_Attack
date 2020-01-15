#include "GameObject.h"



GameObject::GameObject(sf::Texture* texture, int spriteColumns, int spriteRows)
{
	sprite = new sf::Sprite();
	sprite->setTexture(*texture);

	columns = spriteColumns;
	rows = spriteRows;
	centerOrigin();
}


GameObject::~GameObject()
{
	delete sprite;
}

void GameObject::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(*sprite, states);
}

void GameObject::moveSprite(sf::Vector2f dir, float speed)
{
	sprite->move(dir * speed);
}

void GameObject::moveSprite(float velX, float velY)
{
	sprite->move(velX, velY);
}

void GameObject::rotateSprite(float angle)
{
	static const float PI = 3.14159f;
	sprite->setRotation((angle * 180) / PI + 90);
}

void GameObject::setSpriteScale(float scale)
{
	sprite->setScale(scale, scale);
}

void GameObject::centerOrigin()
{
	float originX = sprite->getGlobalBounds().width / (columns * 2);
	float originY = sprite->getGlobalBounds().height / (rows * 2);
	sprite->setOrigin(originX, originY);
}

sf::Sprite* GameObject::getSprite() const
{
	return sprite;
}

void GameObject::setPosition(float x, float y)
{
	sprite->setPosition(x, y);
}

void GameObject::setPosition(sf::Vector2f pos)
{
	sprite->setPosition(pos);
}

sf::FloatRect GameObject::getBounds() const
{
	return sprite->getGlobalBounds();
}

sf::Vector2f GameObject::getPosition() const
{
	return sprite->getPosition();
}
