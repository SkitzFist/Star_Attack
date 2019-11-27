#include "Game.h"
#include "MenuState.h"
#include <chrono>
#include <thread>

Game::Game():
	timePerFrame(sf::seconds(1.0f / 60.0f)),
	elapsedTimeSinceLastUpdate(sf::Time::Zero),
	currentState(nullptr)
{
	rm = new ResourceManager();
	rm->setup();

	window.create(sf::VideoMode(rm->WINDOW_WIDTH, rm->WINDOW_HEIGHT), "Star Attack");

	currentState = new MenuState(rm);
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
		std::this_thread::sleep_for(std::chrono::microseconds(timePerFrame.asMicroseconds()));
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
		currentState = currentState->update(timePerFrame); //Todo: Look into delta time
		elapsedTimeSinceLastUpdate -= timePerFrame;

	}
}


void Game::render()
{
	window.clear();
	currentState->render(window);
	window.display();
}
