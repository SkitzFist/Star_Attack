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

private:
	sf::Vector2f pos;
};

