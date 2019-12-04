#include "Bullet.h"



Bullet::Bullet(sf::Texture* texture)
{
	setTexture(texture);
}


Bullet::~Bullet()
{
}

void Bullet::update(sf::Time delta)
{
	if (getPosition().x < -4 ||
		getPosition().x > rm->WINDOW_WIDTH + 4 ||
		getPosition().y <  -4 ||
		getPosition().y > rm->WINDOW_HEIGHT + 4) {
		
		delete this;
	}
}

void Bullet::move()
{
}

void Bullet::setWindow(ResourceManager* rm)
{
	this->rm = rm;
}
