#include "DeathState.h"
#include "PlayState.h"

DeathState::DeathState(ResourceManager* rm, GameState* playState):
	GameState(rm),
	playState(playState)
{
	startNewGame = false;
	exitGame = false;
	float windowWidth = static_cast<float>(rm->getWindowWidth());
	float windowHeight = static_cast<float>(rm->getWindowHeight());
	box = new Box(rm->getFont(), "game over", windowWidth/2, windowHeight/2);

	greyBox.setSize(sf::Vector2f(windowWidth, windowHeight));
	sf::Color color = { 5,5,5, 150 };
	greyBox.setFillColor(color);
}

DeathState::~DeathState()
{
	delete box;
}

GameState * DeathState::handleEvent(const sf::Event & event)
{
	GameState* state = this;
	if (event.type == sf::Event::KeyReleased) {
		if (event.key.code == sf::Keyboard::Escape) {
			delete playState;
			exitGame = true;
		}
		else if (event.key.code == sf::Keyboard::Return) {
			startNewGame = true;
		}
	}
	return state;
}

GameState * DeathState::update(const sf::Time & delta)
{
	GameState* state = this;

	if (startNewGame) {
		delete playState;
		state = new PlayState(rm);
		delete this;
	}
	return state;
}

void DeathState::render(sf::RenderWindow & window) const
{
	if (!exitGame) {
		playState->render(window);
	}
	
	window.draw(greyBox);
	box->render(window);
}
