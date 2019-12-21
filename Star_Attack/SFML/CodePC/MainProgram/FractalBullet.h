#pragma once
#include "Bullet.h"
#include "BulletHandler.h"

class FractalBullet:
	public Bullet
{
public:
	FractalBullet(sf::Texture* texture, BulletHandler* bh);
	~FractalBullet();

	virtual void updateBullet(sf::Time delta) override;

private:
	int index;
	BulletHandler* bh;

	sf::Time lifeTime;
	sf::Time duration;

	sf::Texture* texture;

private:
	void fractal();
	
};

