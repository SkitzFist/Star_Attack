#include "MenuState.h"
#include "PlayState.h"

MenuState::MenuState(ResourceManager* rm) :
	GameState(rm)
{
	//config
	float space = 50.f;

	//setup
	playBox = new Box(rm->getFont(), "play", static_cast<float>(rm->getWindowWidth() / 2), static_cast<float>(rm->getWindowHeight() / 2));
	exitBox = new Box(rm->getFont(), "exit", static_cast<float>(rm->getWindowWidth() / 2), static_cast<float>((rm->getWindowHeight() / 2) + space));

	currentBox = MenuState::boxes::play;
	playBox->markBox();
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
