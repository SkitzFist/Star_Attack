#include "MenuState.h"
#include "PlayState.h"


MenuState::MenuState()
{
	std::cout << "In menu state" << std::endl;
}


MenuState::~MenuState()
{
}

GameState* MenuState::handleEvent(const sf::Event & event)
{
	GameState* state = this;

	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space) {
		delete state;
		state = new PlayState();
	}

	return state;
}

GameState* MenuState::update(const sf::Time & delta)
{
	return this;
}

void MenuState::render(const sf::RenderWindow & window) const
{
}
