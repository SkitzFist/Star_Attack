#include "PlayState.h"



PlayState::PlayState(ResourceManager* rm):
	GameState(rm)
{
	bh = new BulletHandler();
	sf::Vector2f screenDimensions = { static_cast<float>(rm->getWindowWidth()) , static_cast<float>(rm->getWindowHeight())};
	enemy = new Enemy(GameState::rm->getBossTexture(), screenDimensions, rm, bh);
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

	bh->update(delta, rm);

	return this;
}

void PlayState::render(sf::RenderWindow & window) const
{
	bh->render(window);
	window.draw(*player);
	window.draw(*enemy);
}
