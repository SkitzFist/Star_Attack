#pragma once
#include "EnemyState.h"
class CircleState :
	public EnemyState
{
public:
	CircleState(ResourceManager* rm, BulletHandler* bh);
	virtual ~CircleState();

	// Inherited via EnemyState
	virtual EnemyState * update(sf::Time delta) override;
	virtual void fire() override;
	virtual void takeDamage() override;
private:

	sf::Vector2f pos;
	float timeBetweenShots;
	int nrOfAngles;
	int inc;

	//HealthBar
	int healthRadius;
	int currentHealthRadius;
	int healthInc;
	const int POINTS = 600;
	float angle;
	float offset;

private:
	void updateHealthBar();
	bool isInsideBounds(int x, int y);
};

