#include "Bullet.h"



Bullet::Bullet(sf::Texture* texture):
	GameObject(texture, 1, 1)
{
	//config
	dir = { 0.f,0.f };
	speed = 5.f;

	//setup
	canDelete = false;
}


Bullet::~Bullet()
{
}

void Bullet::setDirection(sf::Vector2f dir)
{
	this->dir = dir;
}

bool Bullet::isColliding(const GameObject & go)
{
	bool isColliding = false;
	if (getBounds().intersects(go.getBounds())) {
		isColliding = true;
	}
	return false;
}

bool Bullet::getCanDelete() const
{
	return canDelete;
}

void Bullet::update(sf::Time delta)
{
	
	move();
	updateBullet(delta);
}

	
void Bullet::move()
{
	moveSprite(dir, speed);
}