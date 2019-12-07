#pragma once
#include <SFML/Graphics.hpp>
#include "ResourceManager.h"
#include "BulletHandler.h"

class Weapon
{
public:
	Weapon(float timeBetweenShots, ResourceManager* rm, BulletHandler* bh);
	virtual ~Weapon();
	virtual void update(sf::Time delta) = 0;
	virtual void fire(sf::Vector2f startPos, sf::Vector2f dir) = 0;

	float getTimeLeft() const;

protected:
	float timeLeft;

protected:
	float getTimeBetweenShots() const;
	ResourceManager* rm;
	BulletHandler* bh;
private:
	float timeBetweenShots;
	
};

