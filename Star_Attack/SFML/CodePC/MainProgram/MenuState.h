#pragma once
#include "GameState.h"
#include "Box.h"

class MenuState : public GameState
{
public:
	MenuState(ResourceManager* rm);
	~MenuState();

	// Inherited via GameState
	virtual GameState* handleEvent(const sf::Event & event) override;
	virtual GameState* update(const sf::Time & delta) override;
	virtual void render(sf::RenderWindow & window) const override;

private:
	sf::Text text;
	Box* playBox;
	Box* exitBox;
};

