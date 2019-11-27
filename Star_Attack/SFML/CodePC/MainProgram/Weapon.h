#pragma once
#include <SFML/Graphics.hpp>
class Weapon
{
public:
	Weapon(float timeBetweenShots);
	virtual ~Weapon();
	virtual void update(sf::Time delta) = 0;
	virtual void fire() = 0;

	float getTimeLeft() const;

protected:
	float timeLeft;

protected:
	float getTimeBetweenShots() const;

private:
	float timeBetweenShots;

};

