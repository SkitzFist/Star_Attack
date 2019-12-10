#pragma once
#include "Entity.h"
#include "ResourceManager.h"
#include "BulletHandler.h"
#include "BossWeapon.h"

class Enemy :
	public Entity
{
public:
	Enemy(sf::Texture* texture, sf::Vector2f pos, ResourceManager* rm, BulletHandler* bh);
	virtual ~Enemy();

	// Inherited via Entity
	virtual void updateObject(sf::Time delta) override;
	virtual void moveObject() override;

private:
	BossWeapon* currentWeapon;
};

