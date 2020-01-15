#include "DeathState.h"
#include "PlayState.h"

DeathState::DeathState(ResourceManager* rm, GameState* playState, std::string text):
	GameState(rm),
	playState(playState)
{
	//config
	float windowWidth = static_cast<float>(rm->getWindowWidth());
	float windowHeight = static_cast<float>(rm->getWindowHeight());
	sf::Color color = { 5,5,5, 150 };
	sf::Vector2f scorePos{
		windowWidth / 2.f - 80.f,
		windowHeight / 3.f
	};

	//setup
	startNewGame = false;
	exitGame = false;

	greyBox.setSize(sf::Vector2f(windowWidth, windowHeight));
	greyBox.setFillColor(color);
	box = new Box(rm->getFont(), "       " + text + "\nEnter to play again\nEsc to quit", windowWidth / 2, windowHeight / 2);
	
	score.setFont(*rm->getFont());
	score.setPosition(scorePos);
	PlayState* pState = dynamic_cast<PlayState*>(playState);
	score.setString("Score: " + std::to_string(pState->getScore()));
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
	window.draw(score);
}
