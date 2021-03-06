#include "PlayState.h"
#include "DeathState.h"


PlayState::PlayState(ResourceManager* rm) :
	GameState(rm)
{
	playerBH = new BulletHandler();
	enemyBh = new BulletHandler();
	sf::Vector2f screenDimensions = { static_cast<float>(rm->getWindowWidth()) , static_cast<float>(rm->getWindowHeight()) };
	enemy = new Enemy(GameState::rm->getBossTexture(), screenDimensions, rm, enemyBh);
	player = new Player(GameState::rm->getPlayerTexture(), playerBH, rm, enemy);
	rm->resetBgrImage();
	canStart = false;
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
	if (event.type == sf::Event::KeyPressed) {
		canStart = true;
	}
	player->input(event);
	return this;
}

GameState* PlayState::update(const sf::Time & delta)
{
	GameState* state = this;
	player->rotateTowards(*enemy);
	player->updateObject(delta);
	player->boundToWindow(rm);

	if (canStart) {

		if (enemy->getIsAlive()) {
			enemy->updateObject(delta);
			enemyBh->update(delta, rm);
			collision.radiusCheckBetween(enemyBh, player);
		}

		playerBH->update(delta, rm);
		collision.checkBetween(playerBH, enemy);

		if (!player->getIsAlive()) {
			state = new DeathState(rm, this);
		}
	}
	return state;
}

void PlayState::render(sf::RenderWindow & window) const
{
	window.draw(*rm->getBgrSprite());
	playerBH->render(window);
	if (enemy->getIsAlive()) {
		enemyBh->render(window);
		window.draw(*enemy);
	}
	window.draw(*player);
	
}
