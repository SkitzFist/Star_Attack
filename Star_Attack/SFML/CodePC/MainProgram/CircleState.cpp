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
	float timeBetweenShots = 0.3f;
	int nrOfAngles = 15;

	//Setup
	currentWeapon = new CircleWeapon(timeBetweenShots, rm, bh, true);

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
