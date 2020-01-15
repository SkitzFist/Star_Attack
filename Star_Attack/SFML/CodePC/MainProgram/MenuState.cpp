#include "MenuState.h"
#include "PlayState.h"
#include <fstream>

MenuState::MenuState(ResourceManager* rm) :
	GameState(rm)
{
	//config
	float space = 50.f;
	sf::Vector2f higeScoreTextPos{
		static_cast<float>(rm->getWindowWidth() / 2.f - 80.f),
		static_cast<float>(rm->getWindowHeight() / 3.f)
	};

	//setup
	playBox = new Box(rm->getFont(), "Play", static_cast<float>(rm->getWindowWidth() / 2), static_cast<float>(rm->getWindowHeight() / 2));
	exitBox = new Box(rm->getFont(), "Exit", static_cast<float>(rm->getWindowWidth() / 2), static_cast<float>((rm->getWindowHeight() / 2) + space));
	currentBox = MenuState::boxes::play;
	playBox->markBox();

	highScoreText.setFont(*rm->getFont());
	highScoreText.setPosition(higeScoreTextPos);
	highscore = getHighScore();
	highScoreText.setString("Best: " + std::to_string(highscore));
}


MenuState::~MenuState()
{
	delete playBox;
	delete exitBox;
}

GameState* MenuState::handleEvent(const sf::Event & event)
{
	GameState* state = this;

	if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::Up
			|| event.key.code == sf::Keyboard::Down) {
			switchBox();
		}
	}

	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return) {
		switch (currentBox)
		{
		case MenuState::play:
			state = new PlayState(rm);
			break;
		case MenuState::exit:
			state = nullptr;
			break;
		default:
			break;
		}

		delete this;
	}

	return state;
}

GameState* MenuState::update(const sf::Time & delta)
{
	return this;
}

void MenuState::render(sf::RenderWindow & window) const
{
	playBox->render(window);
	exitBox->render(window);
	window.draw(highScoreText);
}

int MenuState::getHighScore() const
{
	int value = 0;
	std::ifstream inFile;
	inFile.open(rm->getHighScorePath());
	if (!inFile.fail()) {
		inFile >> value;
	}
	inFile.close();

	return value;
}

void MenuState::switchBox()
{
	switch (currentBox)
	{
	case MenuState::play:
		playBox->unmarkBox();
		exitBox->markBox();
		currentBox = MenuState::boxes::exit;
		break;
	case MenuState::exit:
		exitBox->unmarkBox();
		playBox->markBox();
		currentBox = MenuState::boxes::play;
		break;
	default:
		break;
	}
}
