#include "PlayState.h"
#include "DeathState.h"


PlayState::PlayState(ResourceManager* rm):
	GameState(rm)
{
	playerBH = new BulletHandler();
	enemyBh = new BulletHandler();
	sf::Vector2f screenDimensions = { static_cast<float>(rm->getWindowWidth()) , static_cast<float>(rm->getWindowHeight())};
	enemy = new Enemy(GameState::rm->getBossTexture(), screenDimensions, rm, enemyBh);
	player = new Player(GameState::rm->getPlayerTexture(), playerBH, rm, enemy);
}

PlayState::~PlayState()
{
	delete player;
	delete enemy;
	delete playerBH;
	delete enemyBh;
}

GameState* PlayState::handleEvent(const sf::Event & event)
{
	player->input(event);
	return this;
}

GameState* PlayState::update(const sf::Time & delta)
{
	GameState* state = this;
	player->rotateTowards(*enemy);
	player->updateObject(delta);
	player->boundToWindow(rm);

	enemy->updateObject(delta);

	enemyBh->update(delta, rm);
	playerBH->update(delta, rm);
	
	collision.checkBetween(playerBH, enemy);
	collision.radiusCheckBetween(enemyBh, player);

	if (!player->getIsAlive()) {
		state = new DeathState(rm, this);
	}

	return state;
}

void PlayState::render(sf::RenderWindow & window) const
{
	playerBH->render(window);
	enemyBh->render(window);
	window.draw(*player);
	window.draw(*enemy);
}
