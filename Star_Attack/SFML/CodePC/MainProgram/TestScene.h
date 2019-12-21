#pragma once
#include "GameState.h"
#include "FractalBullet.h"
#include "BulletHandler.h"
class TestScene :
	public GameState
{
public:
	TestScene(ResourceManager* rm);
	~TestScene();

	// Inherited via GameState
	virtual GameState * handleEvent(const sf::Event & event) override;
	virtual GameState * update(const sf::Time & delta) override;
	virtual void render(sf::RenderWindow & window) const override;

private:
	BulletHandler* bh;
};

