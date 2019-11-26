#include "PlayState.h"



PlayState::PlayState(ResourceManager* rm):
	GameState(rm)
{
	player = new Player(GameState::rm->getPlayerTexture());
}

PlayState::~PlayState()
{
	delete player;
}

GameState* PlayState::handleEvent(const sf::Event & event)
{
	player->input(event);
	return this;
}

GameState* PlayState::update(const sf::Time & delta)
{
	player->update(delta);
	return this;
}

void PlayState::render(sf::RenderWindow & window) const
{
	window.draw(*player);
}
