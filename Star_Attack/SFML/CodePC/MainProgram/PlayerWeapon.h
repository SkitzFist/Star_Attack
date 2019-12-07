#pragma once
#include "Weapon.h"
class PlayerWeapon :
	public Weapon
{
public:
	PlayerWeapon(float timeBetweenShots, ResourceManager* rm, BulletHandler* bh);
	virtual ~PlayerWeapon();

	// Inherited via Weapon
	virtual void update(sf::Time delta) override;
	virtual void fire(sf::Vector2f startPos, sf::Vector2f dir) override;
};