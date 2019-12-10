#pragma once
#include "Weapon.h"
class PlayerWeapon :
	public Weapon
{
public:
	PlayerWeapon(float timeBetweenShots, ResourceManager* rm, BulletHandler* bh);
	virtual ~PlayerWeapon();

	// Inherited via Weapon
	void fire(sf::Vector2f startPos, sf::Vector2f dir);
	virtual void fire(sf::Vector2f pos) override;

};