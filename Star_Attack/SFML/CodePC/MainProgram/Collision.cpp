#include "Collision.h"



Collision::Collision()
{
}


Collision::~Collision()
{
}

void Collision::checkBetween(BulletHandler *bh, Entity * entity)
{
	short index = 0;

	while (index < bh->getNrOf() && entity->getIsAlive()) {
		if (bh->getBullets()[index]->getBounds().intersects(entity->getBounds())) {

			entity->takeDamage();
			bh->removeBulletAt(index);
			
		}
		index++;
	}
}

void Collision::radiusCheckBetween(BulletHandler *bh, Entity * entity)
{
	short index = 0;
	float radius = 12.5f;

	while (index < bh->getNrOf() && entity->getIsAlive()) {
		Bullet* bullet = bh->getBullets()[index];
		sf::Vector2f delta = {
			bullet->getPosition().x - entity->getPosition().x,
			bullet->getPosition().y - entity->getPosition().y
		};
		float length = sqrt(delta.x * delta.x + delta.y * delta.y);

		if (length <= radius) {
			entity->takeDamage();
			bh->removeBulletAt(index);
		}

		index++;
	}
}
