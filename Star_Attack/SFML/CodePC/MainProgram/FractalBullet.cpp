#include "FractalBullet.h"



FractalBullet::FractalBullet(sf::Texture* texture, BulletHandler* bh) :
	Bullet(texture)
{
	//config
	lifeTime = sf::seconds(1.f);
	angle = 35.f;

	//setup
	duration = sf::Time::Zero;
	this->bh = bh;
	this->texture = texture;
}

FractalBullet::~FractalBullet()
{
	
}

void FractalBullet::updateBullet(sf::Time delta)
{
	duration += delta;
	if (duration > lifeTime) {
		fractal();
	}
}

void FractalBullet::fractal()
{

	const float PI = 3.141592f;
	float dirAngle = atan2(dir.y, dir.x);
	dirAngle *= 180 / PI;
	float newAngle = (dirAngle + angle) * PI / 180;
	sf::Vector2f newDir{
		cos(newAngle),
		sin(newAngle)
	};

	Bullet* bullet = new FractalBullet(texture, bh);
	bullet->setPosition(getPosition());
	bullet->setDirection(newDir);
	bh->addBullet(bullet);

	newAngle = (dirAngle - angle) * PI / 180;
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
