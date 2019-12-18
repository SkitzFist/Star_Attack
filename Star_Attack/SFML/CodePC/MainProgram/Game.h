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
	sf::Time elapsedTime;
	sf::Time timePerFrame;
	sf::RenderWindow window;

	GameState *currentState;
	ResourceManager* rm;
private:
	void handleEvent();
	void update();
	void render();

	sf::Image* createBgrImage() const;

};

