#include "EnemyState.h"



EnemyState::EnemyState(ResourceManager* rm, BulletHandler* bh):
	rm(rm),
	bh(bh)
{
}


EnemyState::~EnemyState()
{
 	delete currentWeapon;
}