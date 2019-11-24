#pragma once
#include <SFML/Graphics.hpp>
#include <iostream> // TODO: remove this

class GameState
{

public:
	GameState();
	virtual ~GameState();

	virtual GameState* handleEvent(const sf::Event &event) = 0;
	virtual GameState* update(const sf::Time &delta) = 0;
	virtual void render(const sf::RenderWindow &window) const = 0;
};

