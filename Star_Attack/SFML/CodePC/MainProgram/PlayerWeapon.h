#pragma once
#include "Weapon.h"
class PlayerWeapon :
	public Weapon
{
public:
	PlayerWeapon(float timeBetweenShots);
	virtual ~PlayerWeapon();

	// Inherited via Weapon
	virtual void update(sf::Time delta) override;
	virtual void fire() override;
};