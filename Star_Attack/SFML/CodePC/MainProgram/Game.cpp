#include "Game.h"



Game::Game():
	window(sf::VideoMode(WIDTH, HEIGHT), "THE BEST GAME EVER"),
	timePerFrame(sf::seconds(1.0f / 60.0f)),
	elapsedTimeSinceLastUpdate(sf::Time::Zero)
{

}


Game::~Game()
{
}

void Game::run()
{
	while (window.isOpen())
	{
		handleEvent();
		update();
		render();
	}
}

void Game::update()
{
	elapsedTimeSinceLastUpdate += clock.restart();
	if (elapsedTimeSinceLastUpdate > timePerFrame) {

		elapsedTimeSinceLastUpdate -= timePerFrame;

	}
}

void Game::handleEvent()
{
	sf::Event event;
	while (window.pollEvent(event)) {

		if (event.type == sf::Event::Closed ||
			event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape) {
			window.close();
		}

	}
}

void Game::render()
{
	window.clear();
	window.display();
}
