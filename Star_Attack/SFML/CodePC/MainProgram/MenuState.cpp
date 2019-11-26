#include "MenuState.h"
#include "PlayState.h"


MenuState::MenuState(ResourceManager* rm):
	GameState(rm)
{
	text.setFont(*rm->getFont());
	text.setPosition(100.f, 300.f);
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(52);
	text.setString("press space to start");
}


MenuState::~MenuState()
{
}

GameState* MenuState::handleEvent(const sf::Event & event)
{
	GameState* state = this;

	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space) {
		state = new PlayState(rm);
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
	window.draw(text);
}
