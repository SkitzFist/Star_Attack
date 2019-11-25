#include "Game.h"
#include "MenuState.h"
#include "PlayState.h"


Game::Game():
	window(sf::VideoMode(WIDTH, HEIGHT), "Star Attack"),
	timePerFrame(sf::seconds(1.0f / 60.0f)),
	elapsedTimeSinceLastUpdate(sf::Time::Zero),
	currentState(nullptr)
{
	rm = new ResourceManager();
	rm->setup();
	currentState = new PlayState(rm);
}


Game::~Game()
{
	delete rm;
	delete currentState;	
}

void Game::run()
{
	while (window.isOpen())
	{
		handleEvent();
		update();
		render();
		window.setFramerateLimit(60);
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
		currentState = currentState->handleEvent(event);
	}
}

void Game::update()
{
	elapsedTimeSinceLastUpdate += clock.restart();

	if (elapsedTimeSinceLastUpdate > timePerFrame) {

		currentState = currentState->update(elapsedTimeSinceLastUpdate);
		elapsedTimeSinceLastUpdate -= timePerFrame;
	}
}


void Game::render()
{
	window.clear();
	currentState->render(window);
	window.display();
}
