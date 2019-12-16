#pragma once
#include "GameState.h"
#include "Player.h"
#include "Enemy.h"
#include "BulletHandler.h"
#include "Collision.h"

class PlayState :
	public GameState
{
public:
	PlayState(ResourceManager* rm);
	virtual ~PlayState();

	// Inherited via GameState
	virtual GameState* handleEvent(const sf::Event & event) override;
	virtual GameState* update(const sf::Time & delta) override;
	virtual void render(sf::RenderWindow & window) const override;

private:
	Player* player;
	BulletHandler* playerBH;
	Enemy* enemy;
	BulletHandler* enemyBh;
	Collision collision;

	sf::Sprite* bgr;
};

