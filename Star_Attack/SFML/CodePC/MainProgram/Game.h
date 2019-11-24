#pragma once
#include <SFML/Graphics.hpp>

class Game
{
public:
	static const int WIDTH = 900;
	static const int HEIGHT = 600;
public:
	Game();
	~Game();
	void run();

private:
	sf::Clock clock;
	sf::Time elapsedTimeSinceLastUpdate;
	sf::Time timePerFrame;
	sf::RenderWindow window;

private:
	void update();
	void handleEvent();
	void render();


};

