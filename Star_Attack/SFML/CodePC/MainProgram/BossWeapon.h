#pragma once
#include "Weapon.h"
class BossWeapon :
	public Weapon
{
public:
	BossWeapon(float timeBetweenShots, ResourceManager* rm, BulletHandler* bh);
	virtual ~BossWeapon();

	virtual void Setup(sf::Vector2f pos, int nrOfAngles) = 0;
	virtual void fireBoss(sf::Vector2f pos) = 0;

	int getNrOfAngles() const;

	// Inherited via Weapon
	virtual void fire(sf::Vector2f pos) override;
	
protected:
	sf::Vector2f* angles;
	int nrOfAngles;

};

