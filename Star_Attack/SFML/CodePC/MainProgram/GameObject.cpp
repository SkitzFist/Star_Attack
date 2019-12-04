#include "GameObject.h"



GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}

void GameObject::setTexture(sf::Texture * texture)
{
	sprite.setTexture(*texture);
	sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
}

void GameObject::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(sprite, states);
}

void GameObject::moveSprite(sf::Vector2f dir, float speed)
{
	sprite.move(dir * speed);
}

void GameObject::moveSprite(float velX, float velY)
{
	sprite.move(velX, velY);
}

void GameObject::rotateSprite(float angle)
{
	static const float PI = 3.14159f;
	sprite.setRotation((angle * 180) / PI + 270.f);
}

void GameObject::setPosition(float x, float y)
{
	sprite.setPosition(x, y);
}

void GameObject::setPosition(sf::Vector2f pos)
{
	sprite.setPosition(pos);
}

sf::FloatRect GameObject::getBounds() const
{
	return sprite.getGlobalBounds();
}

sf::Vector2f GameObject::getPosition() const
{
	return sprite.getPosition();
}
