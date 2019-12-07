#include "Bullet.h"



Bullet::Bullet(sf::Texture* texture):
	GameObject(texture)
{
	//config
	dir = { 0.f,0.f };
	id = 0;
	speed = 5.f;
}


Bullet::~Bullet()
{
}

int Bullet::getId() const
{
	return id;
}

void Bullet::setup(sf::Vector2f dir)
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

void Bullet::update(sf::Time delta)
{
	move();
}

void Bullet::move()
{
	moveSprite(dir, speed);
}