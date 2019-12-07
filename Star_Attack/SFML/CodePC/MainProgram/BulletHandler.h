#pragma once
#include "Bullet.h"
class BulletHandler
{
public:
	BulletHandler();
	~BulletHandler();

	void update(sf::Time delta);
	void render(sf::RenderWindow &window);
	bool isColliding(const Entity &entity);
	void addBullet(Bullet* bullet);
private:
	int capacity;
	int nrOf;
	Bullet** bullets;

private:
	void removeBullet(int index);
	void shrinkArrFrom(int index);
	void expandArr();
};

