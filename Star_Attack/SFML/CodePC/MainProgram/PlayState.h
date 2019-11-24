#pragma once
#include "GameState.h"
class PlayState :
	public GameState
{
public:
	PlayState();
	virtual ~PlayState();

	// Inherited via GameState
	virtual GameState* handleEvent(const sf::Event & event) override;
	virtual GameState* update(const sf::Time & delta) override;
	virtual void render(const sf::RenderWindow & window) const override;
};

