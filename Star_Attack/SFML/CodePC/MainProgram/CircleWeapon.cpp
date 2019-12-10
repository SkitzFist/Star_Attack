#include "CircleWeapon.h"



CircleWeapon::CircleWeapon(float timeBetweenShots, ResourceManager* rm, BulletHandler* bh):
	BossWeapon(timeBetweenShots, rm, bh)
{
	//config
	radius = 1.f;

	//setup
	index = 0;
}


CircleWeapon::~CircleWeapon()
{
}

void CircleWeapon::Setup(sf::Vector2f pos, int nrOfAngles)
{
	this->nrOfAngles = nrOfAngles;
	angles = new sf::Vector2f[nrOfAngles];

	const float PI = 3.141592f;
	float angle = PI * 2.f / static_cast<float>(nrOfAngles);
	float offset = 0.f;
	for (int i = 0; i < nrOfAngles; ++i) {
		sf::Vector2f tmp= {
			pos.x + radius * cos(angle + offset),
			pos.y - radius * sin(angle + offset)
		};
		sf::Vector2f delta = {
			tmp.x - pos.x,
			tmp.y - pos.y
		};
		float magnitude = sqrt(delta.x * delta.x + delta.y * delta.y);
		angles[i] = {
			delta.x / magnitude,
			delta.y / magnitude
		};
		offset += angle;
	}
}

void CircleWeapon::fireBoss(sf::Vector2f pos)
{
	for (int i = 0; i < nrOfAngles; ++i) {
		Bullet* bullet = new Bullet(rm->getWhiteBallTexture());
		bullet->setPosition(pos);
		bullet->setDirection(angles[i]);
		bh->addBullet(bullet);
		timeLeft = getTimeBetweenShots();
	}
	
}
