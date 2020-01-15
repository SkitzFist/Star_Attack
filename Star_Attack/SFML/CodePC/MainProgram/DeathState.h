#pragma once
#include "GameState.h"
#include "Box.h"

class DeathState :
	public GameState
{
public:
	DeathState(ResourceManager* rm, GameState* state, std::string text);
	virtual ~DeathState();

	// Inherited via GameState
	virtual GameState * handleEvent(const sf::Event & event) override;
	virtual GameState * update(const sf::Time & delta) override;
	virtual void render(sf::RenderWindow & window) const override;

private:
	GameState* playState;
	Box* box;
	bool startNewGame;
	bool exitGame;
	sf::RectangleShape greyBox;

	sf::Text score;
};

