#pragma once
#include "Entity.h"
#include "ResourceManager.h"
class Bullet :
	public GameObject
{
public:
	Bullet(sf::Texture* texture);
	virtual ~Bullet();

	// Inherited via Entity
	virtual void update(sf::Time delta) override;
	virtual void move() override;
	void setWindow(ResourceManager* rm);

private:
	ResourceManager* rm;
};

