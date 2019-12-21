#pragma once
#include "Bullet.h"
class normalBullet : 
	public Bullet
{
public:
	normalBullet(sf::Texture* texture);
	~normalBullet();

	// Inherited via Bullet
	virtual void updateBullet(sf::Time delta) override;
};

