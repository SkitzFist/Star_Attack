#include "PlayState.h"



PlayState::PlayState()
{
	std::cout << "In play state" << std::endl;
}


PlayState::~PlayState()
{
}

GameState* PlayState::handleEvent(const sf::Event & event)
{

	return this;
}

GameState* PlayState::update(const sf::Time & delta)
{

	return this;
}

void PlayState::render(const sf::RenderWindow & window) const
{
}
