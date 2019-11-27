#pragma once
#include "Entity.h"
class Bullet :
	public Entity
{
public:
	Bullet(sf::Texture* texture);
	virtual ~Bullet();

	// Inherited via Entity
	virtual void update(sf::Time delta) override;
	virtual void move() override;
};

