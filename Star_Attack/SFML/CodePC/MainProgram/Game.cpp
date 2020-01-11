#include "Game.h"
#include "MenuState.h"
#include <chrono>
#include <thread>

Game::Game():
	timePerFrame(sf::seconds(1.0f / 60.0f)),
	elapsedTime(sf::Time::Zero),
	currentState(nullptr)
{	
	auto fullscreenModes = sf::VideoMode::getFullscreenModes();
	int styles = sf::Style::Fullscreen | sf::Style::Titlebar | sf::Style::Close;
	
	rm = new ResourceManager();
	rm->setup(fullscreenModes.front().width, fullscreenModes.front().height);
	rm->setupBgrImage(createBgrImage());

	window.create(fullscreenModes.front(), "Star Attack", styles);
	window.setMouseCursorVisible(false);

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
	elapsedTime += clock.restart();
	if (elapsedTime > timePerFrame) {
		currentState = currentState->update(elapsedTime); 
		elapsedTime = sf::Time::Zero;
	}
}


void Game::render()
{
	window.clear();
	currentState->render(window);
	window.display();
}

sf::Image * Game::createBgrImage() const
{
	sf::Image* tile;
	tile = new sf::Image();
	if (!tile->loadFromFile("../Sprites/tile_01.png")) {
		throw std::runtime_error("Could not load tile.png");
	}

	const int TILE_X = tile->getSize().x;
	const int TILE_Y = tile->getSize().y;

	sf::Image* bgrImage = new sf::Image();
	bgrImage->create(rm->getWindowWidth(), rm->getWindowHeight());

	int tileXPos = 0;
	int tileYPos = 0;

	for (int x = 0; x < rm->getWindowWidth(); ++x) {
		for (int y = 0; y < rm->getWindowHeight(); ++y) {

			sf::Color color = tile->getPixel(tileXPos, tileYPos);
			bgrImage->setPixel(x, y, color);
			tileYPos += 1;
			if (y % TILE_Y == 0) {
				tileYPos = 0;
			}
		}
		tileXPos += 1;
		if (x % TILE_X == 0) {
			tileXPos = 0;
		}
	}

	delete tile;
	return bgrImage;
}
