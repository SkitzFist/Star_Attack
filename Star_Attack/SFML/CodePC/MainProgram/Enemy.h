#pragma once
#include "Entity.h"
class Enemy :
	public Entity
{
public:
	Enemy(sf::Texture* texture, float x, float y);
	virtual ~Enemy();

	// Inherited via Entity
	virtual void updateObject(sf::Time delta) override;
	virtual void moveObject() override;
};

