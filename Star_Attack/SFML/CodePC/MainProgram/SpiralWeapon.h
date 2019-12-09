#pragma once
#include "Weapon.h"
class SpiralWeapon:
	public Weapon
{
public:
	SpiralWeapon(float timeBetweenShots, ResourceManager* rm, BulletHandler* bh);
	~SpiralWeapon();

	// Inherited via Weapon
	virtual void fire(sf::Vector2f startPos, sf::Vector2f dir) override;
	virtual void fire() override;

private:
	sf::Vector2f *pos;

};

