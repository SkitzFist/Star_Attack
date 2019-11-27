#pragma once
#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "ResourceManager.h"

class Game
{
public:
	Game();
	~Game();
	void run();

private:
	sf::Clock clock;
	sf::Time elapsedTimeSinceLastUpdate;
	sf::Time timePerFrame;
	sf::RenderWindow window;

	GameState *currentState;
	ResourceManager* rm;
private:
	void handleEvent();
	void update();
	void render();

};

