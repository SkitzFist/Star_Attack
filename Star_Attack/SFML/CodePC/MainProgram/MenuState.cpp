#include "MenuState.h"
#include "PlayState.h"


MenuState::MenuState(ResourceManager* rm):
	GameState(rm)
{
	playBox = new Box(rm->getFont(), "play", static_cast<float>(rm->getWindowWidth() / 2), static_cast<float>(rm->getWindowHeight() / 2));
	exitBox = new Box(rm->getFont(), "exit", static_cast<float>(rm->getWindowWidth() / 2), static_cast<float>((rm->getWindowHeight() / 2) + 50.f));

}


MenuState::~MenuState()
{
	delete playBox;
	delete exitBox;
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
	playBox->render(window);
	exitBox->render(window);
}
