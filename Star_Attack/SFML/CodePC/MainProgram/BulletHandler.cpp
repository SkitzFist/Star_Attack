#include "BulletHandler.h"



BulletHandler::BulletHandler()
{
	//config
	capacity = 60;
	nrOf = 0;
	bullets = new Bullet*[capacity] { nullptr };

}

BulletHandler::~BulletHandler()
{
	for (int i = 0; i < nrOf; ++i) {
		delete bullets[i];
	}
	delete[] bullets;
}

void BulletHandler::update(sf::Time delta)
{
	for (int i = 0; i < nrOf; ++i) {
		bullets[i]->update(delta);

		if (bullets[i]->getPosition().x < -10 || bullets[i]->getPosition().x > 1920 || //TODO:: remove hardcoded values
			bullets[i]->getPosition().y < -10 || bullets[i]->getPosition().y > 1920) {
			removeBullet(i);
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
			removeBullet(i);
			isColliding = true;
		}
	}
	return isColliding;
}

void BulletHandler::addBullet(Bullet * bullet)
{
	std::cout << "Bullet added" << std::endl;
	if (nrOf == capacity) {
		expandArr();
	}
	bullets[nrOf++] = bullet;
}

void BulletHandler::removeBullet(int index)
{
	std::cout << "Removed bullet" << std::endl;
	delete bullets[index];
	shrinkArrFrom(index);
	--nrOf;
}

void BulletHandler::shrinkArrFrom(int index)
{
	for (int i = index; i < nrOf - 1; ++i) {
		bullets[i] = bullets[i + 1];
	}
}

void BulletHandler::expandArr()
{
	std::cout << "Expanding Bullet List" << std::endl;
	capacity += 20;
	Bullet** tmp = new Bullet*[capacity] {nullptr};

	for (int i = 0; i < nrOf; ++i) {
		tmp[i] = bullets[i];
	}
	delete[] bullets;
	bullets = tmp;
}
