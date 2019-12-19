#include "CircleState.h"
#include "CircleWeapon.h"


CircleState::CircleState(ResourceManager* rm, BulletHandler* bh) :
	EnemyState(rm, bh)
{
	//Config:
	pos = {
		static_cast<float>(rm->getWindowWidth() / 2.f),
		static_cast<float>(rm->getWindowHeight() / 2.f)
	};
	timeBetweenShots = 0.8f;
	nrOfAngles = 5;
	health = 5;

	//Setup
	inc = 0;
	currentWeapon = new CircleWeapon(timeBetweenShots, rm, bh);
	currentWeapon->Setup(pos, nrOfAngles); 

	healthRadius = 0;
	currentHealthRadius = 0;
	healthInc = 0;
	const float PI = 3.141592653f;
	angle = (PI * 2) / POINTS;
	offset = 0;

}


CircleState::~CircleState()
{
	
}

EnemyState * CircleState::update(sf::Time delta)
{
	EnemyState* state = this;

	currentWeapon->update(delta);

	if (currentWeapon->getTimeLeft() <= 0.f) {
		fire();
	}

	if (currentHealthRadius != healthRadius) {
		updateHealthBar();
		currentHealthRadius = healthRadius;
	}

	return state;
}

void CircleState::fire()
{
	currentWeapon->fire(pos);

	//sf::Vector2f p1{
	//	250.f,
	//	100.f
	//};
	//currentWeapon->fire(p1);
	//sf::Vector2f p2{
	//	static_cast<float>(rm->getWindowWidth() - 250.f),
	//	100.f
	//};
	//currentWeapon->fire(p2);
	//sf::Vector2f p3{
	//250.f,
	//static_cast<float>(rm->getWindowHeight() - 100.f)
	//};
	//currentWeapon->fire(p3);
	//sf::Vector2f p4{
	//static_cast<float>(rm->getWindowWidth() - 250.f),
	//static_cast<float>(rm->getWindowHeight() - 100.f)
	//};
	//currentWeapon->fire(p4);
	
}

void CircleState::takeDamage()
{

	if (healthInc % 2 == 0) {
		++healthRadius;
		healthInc = 0;
	}
	
	--health;
	if (health <= 0) {
		
		delete currentWeapon;
		++inc;
		if (inc == 4 && nrOfAngles < 50 ) {
			++nrOfAngles;
			inc = 0;
			std::cout << "Angles: " << nrOfAngles << std::endl;
		}
		
		timeBetweenShots -= 0.015f;
		if (timeBetweenShots <= 0.05) {
			timeBetweenShots = 1.2f;
			static int count = 0;
			std::cout << ++count << std::endl;
		}


		currentWeapon = new CircleWeapon(timeBetweenShots, rm, bh, true);
		currentWeapon->Setup(pos, nrOfAngles);
		health = 5;
	}

	++healthInc;
}

void CircleState::updateHealthBar()
{
	sf::Image* image = rm->getBgrImage();
	for (int i = 0; i < POINTS; ++i) {
		float xPos = (rm->getWindowWidth() / 2) + healthRadius * cos(offset);
		float yPos = (rm->getWindowHeight() / 2) - healthRadius * sin(offset);

		int x = static_cast<int>(round(xPos));
		int y = static_cast<int>(round(yPos));
		if (isInsideBounds(x, y)) {
			if (image->getPixel(x, y).r < 40 &&
				image->getPixel(x, y).g > 0 &&
				image->getPixel(x, y).b > 0) {

				sf::Color color = { 128,2,0,255 };
				image->setPixel(x, y, color);
			}
		}
		offset += angle;
	}

	if (healthRadius < (rm->getWindowWidth() / 2)) {
		++healthRadius;
	}
	rm->getBgrTexture()->loadFromImage(*image);
}

bool CircleState::isInsideBounds(int x, int y)
{
	bool isInside = false;
	if (x > 0 && x < rm->getWindowWidth() &&
		y > 0 && y < rm->getWindowHeight()) {
		isInside = true;
	}
	return isInside;
}
