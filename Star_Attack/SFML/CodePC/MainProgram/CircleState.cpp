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
	currentWeapon = new CircleWeapon(timeBetweenShots, rm, bh);

	currentWeapon->Setup(pos, nrOfAngles); 
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
	--health;

	if (health <= 0) {
		delete currentWeapon;

		static int inc = 0;
		++inc;
		if (inc == 4 && nrOfAngles < 50 ) {
			++nrOfAngles;
			inc = 0;
			std::cout << "Angles: " << nrOfAngles << std::endl;;
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
}
