#pragma once
#include <SFML/Graphics.hpp>
#include "GameState.h"

class Game
{
public:
	static const int WIDTH = 900;
	static const int HEIGHT = 600;
public:
	Game();
	~Game();
	void run();
	void changeState(int state);

private:
	sf::Clock clock;
	sf::Time elapsedTimeSinceLastUpdate;
	sf::Time timePerFrame;
	sf::RenderWindow window;

	GameState *currentState;
	
private:
	void handleEvent();
	void update();
	void render();

};

