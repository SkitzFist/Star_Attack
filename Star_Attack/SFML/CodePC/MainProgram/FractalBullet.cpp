#include "FractalBullet.h"



FractalBullet::FractalBullet(sf::Texture* texture, BulletHandler* bh) :
	Bullet(texture)
{
	this->bh = bh;
	this->texture = texture;
	lifeTime = sf::seconds(2.f);
	duration = sf::Time::Zero;
}


FractalBullet::~FractalBullet()
{
}

void FractalBullet::updateBullet(sf::Time delta)
{
	duration += delta;
	if (duration.asSeconds() > 2.f) {
		fractal();
	}
}

void FractalBullet::fractal()
{

	float angle = 25.f;
	const float PI = 3.141592f;
	float dirAngle = atan2(dir.y, dir.x);
	std::cout << dirAngle << std::endl;
	float newAngle = ((dirAngle + angle) + PI) / 180;
	sf::Vector2f newDir{
		cos(newAngle),
		sin(newAngle)
	};

	Bullet* bullet = new FractalBullet(texture, bh);
	bullet->setPosition(getPosition());
	bullet->setDirection(newDir);
	bh->addBullet(bullet);

	newAngle = ((dirAngle - angle) + PI) / 180;
	newDir = {
		cos(newAngle),
		sin(newAngle)
	};
	Bullet* bullet2 = new FractalBullet(texture, bh);
	bullet2->setPosition(getPosition());
	bullet2->setDirection(newDir);
	bh->addBullet(bullet2);

	canDelete = true;
}
