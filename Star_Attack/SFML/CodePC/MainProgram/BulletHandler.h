#pragma once
#include "Bullet.h"
class BulletHandler
{
public:
	BulletHandler();
	~BulletHandler();

	void update(sf::Time delta, ResourceManager* rm);
	void render(sf::RenderWindow &window);
	bool isColliding(const GameObject &entity);
	void addBullet(Bullet* bullet);
	int getNrOf() const;
	void removeBulletAt(int index);
	Bullet** getBullets();

private:
	float offset;
	int capacity;
	int nrOf;
	Bullet** bullets;

private:
	void expandArr();
};

