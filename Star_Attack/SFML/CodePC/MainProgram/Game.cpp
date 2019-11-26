#include "Game.h"
#include "MenuState.h"
#include <chrono>
#include <thread>

Game::Game():
	window(sf::VideoMode(WIDTH, HEIGHT), "Star Attack", sf::Style::Fullscreen),
	timePerFrame(sf::seconds(1.0f / 60.0f)),
	elapsedTimeSinceLastUpdate(sf::Time::Zero),
	currentState(nullptr)
{
	rm = new ResourceManager();
	rm->setup();
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
