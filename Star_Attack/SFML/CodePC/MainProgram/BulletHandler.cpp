#include "BulletHandler.h"
#include "ResourceManager.h"


BulletHandler::BulletHandler()
{
	//config
	capacity = 60;
	nrOf = 0;
	offset = 10.f;
	bullets = new Bullet*[capacity] { nullptr };

}

BulletHandler::~BulletHandler()
{
	for (int i = 0; i < nrOf; ++i) {
		delete bullets[i];
	}
	delete[] bullets;
}

void BulletHandler::update(sf::Time delta, ResourceManager* rm)
{
	offset = 10.f;
	for (int i = 0; i < nrOf; ++i) {
		bullets[i]->update(delta);

		if (bullets[i]->getPosition().x < 0 - offset || bullets[i]->getPosition().x > rm->getWindowWidth() + offset ||
			bullets[i]->getPosition().y < 0 - offset || bullets[i]->getPosition().y > rm->getWindowHeight() + offset) {
			removeBulletAt(i);
		}
	}
}

void BulletHandler::render(sf::RenderWindow &window)
{
	for (int i = 0; i < nrOf; ++i) {
		window.draw(*bullets[i]);
	}
}

bool BulletHandler::isColliding(const GameObject & go)
{
	bool isColliding = false;

	for (int i = 0; i < nrOf; ++i) {
		if (bullets[i]->isColliding(go)) {
			removeBulletAt(i);
			isColliding = true;
		}
	}
	return isColliding;
}

void BulletHandler::addBullet(Bullet * bullet)
{
	if (nrOf == capacity) {
		expandArr();
	}
	bullets[nrOf++] = bullet;
}

int BulletHandler::getNrOf() const
{
	return nrOf;
}

Bullet ** BulletHandler::getBullets()
{
	return bullets;
}

void BulletHandler::removeBulletAt(int index)
{
	delete bullets[index];
	bullets[index] = bullets[--nrOf];
	bullets[nrOf] = nullptr;
}

void BulletHandler::shrinkArrFrom(int index)
{
	for (int i = index; i < nrOf - 1; ++i) {
		bullets[i] = bullets[i + 1];
	}
}

void BulletHandler::expandArr()
{
	capacity += 20;
	Bullet** tmp = new Bullet*[capacity] {nullptr};

	for (int i = 0; i < nrOf; ++i) {
		tmp[i] = bullets[i];
	}
	delete[] bullets;
	bullets = tmp;
}
