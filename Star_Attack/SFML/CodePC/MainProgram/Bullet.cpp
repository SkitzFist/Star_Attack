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

void Bullet::update(sf::Time delta)
{
	move();
}

void Bullet::move()
{
	moveSprite(dir, speed);
}