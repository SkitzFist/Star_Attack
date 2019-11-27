#include "PlayState.h"



PlayState::PlayState(ResourceManager* rm):
	GameState(rm)
{
	player = new Player(GameState::rm->getPlayerTexture());
	enemy = new Enemy(GameState::rm->getBossTexture(), rm->WINDOW_WIDTH, rm->WINDOW_HEIGHT);
}

PlayState::~PlayState()
{
	delete player;
	delete enemy;
}

GameState* PlayState::handleEvent(const sf::Event & event)
{
	player->input(event);
	return this;
}

GameState* PlayState::update(const sf::Time & delta)
{
	player->rotateTowards(*enemy);
	player->update(delta);
	player->boundToWindow(rm);

	enemy->update(delta);
	return this;
}

void PlayState::render(sf::RenderWindow & window) const
{
	window.draw(*player);
	window.draw(*enemy);
}
