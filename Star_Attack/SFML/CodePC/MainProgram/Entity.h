#pragma once
#include "GameObject.h"

class Entity : public GameObject
{
public:
	Entity(sf::Texture* texture);
	virtual ~Entity();

protected:

	virtual void update(sf::Time delta) override;
	virtual void updateObject(sf::Time delta) = 0;
	virtual void move() override;
	virtual void moveObject() = 0;
};

