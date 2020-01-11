#pragma once
#include <SFML/Graphics.hpp>
#include "ResourceManager.h"
#include "BulletHandler.h"

class Weapon
{
public:
	Weapon(float timeBetweenShots, ResourceManager* rm, BulletHandler* bh);
	virtual ~Weapon();
	
	void update(sf::Time delta);
	virtual void fire(sf::Vector2f pos) = 0;
	float getTimeLeft() const;
	void setTimeBetweenShots(float value);
protected:
	float timeLeft;
	ResourceManager* rm;
	BulletHandler* bh;

protected:
	float getTimeBetweenShots() const;

private:
	float timeBetweenShots;

};

