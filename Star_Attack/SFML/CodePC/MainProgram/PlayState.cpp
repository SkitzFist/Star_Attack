#include "PlayState.h"



PlayState::PlayState(ResourceManager* rm):
	GameState(rm)
{
	bh = new BulletHandler();
	enemy = new Enemy(GameState::rm->getBossTexture(), rm->WINDOW_WIDTH, rm->WINDOW_HEIGHT);
	player = new Player(GameState::rm->getPlayerTexture(), bh, rm, enemy);
}

PlayState::~PlayState()
{
	delete player;
	delete enemy;
	delete bh;
}

GameState* PlayState::handleEvent(const sf::Event & event)
{
	player->input(event);
	return this;
}

GameState* PlayState::update(const sf::Time & delta)
{

	player->rotateTowards(*enemy);
	player->updateObject(delta);
	player->boundToWindow(rm);

	enemy->updateObject(delta);

	bh->update(delta);

	return this;
}

void PlayState::render(sf::RenderWindow & window) const
{
	window.draw(*player);
	window.draw(*enemy);
	bh->render(window);
}
