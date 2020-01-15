#include "PlayState.h"
#include "DeathState.h"
#include <fstream>
#include <iostream>

PlayState::PlayState(ResourceManager* rm) :
	GameState(rm)
{
	//Config
	sf::Vector2f screenDimensions = { static_cast<float>(rm->getWindowWidth()) , static_cast<float>(rm->getWindowHeight()) };
	sf::Vector2f scoreTextPos{
		screenDimensions.x / 2.f,
		27.5f
	};

	//Setup
	playerBH = new BulletHandler();
	enemyBh = new BulletHandler();
	enemy = new Enemy(GameState::rm->getBossTexture(), screenDimensions, rm, enemyBh);
	player = new Player(GameState::rm->getPlayerTexture(), playerBH, rm, enemy);
	rm->resetBgrImage();
	scoreText.setFont(*rm->getFont());
	scoreText.setPosition(scoreTextPos);
}

PlayState::~PlayState()
{
	delete player;
	delete enemy;
	delete playerBH;
	delete enemyBh;
}

int PlayState::getScore() const
{
	return player->getScore();
}

GameState* PlayState::handleEvent(const sf::Event & event)
{
	state = this;
	player->input(event);
	return state;
}

GameState* PlayState::update(const sf::Time & delta)
{
	state = this;
	player->rotateTowards(*enemy);
	player->updateObject(delta);
	player->boundToWindow(rm);

	if (enemy->getIsAlive()) {
		enemy->updateObject(delta);
		enemyBh->update(delta, rm);
		collision.radiusCheckBetween(enemyBh, player);
	}

	playerBH->update(delta, rm);
	collision.checkBetween(playerBH, enemy);

	scoreText.setString(std::to_string(player->getScore()));

	if (!player->getIsAlive()) {
		state = new DeathState(rm, this, "Game Over!");
		if (isHighScore()) {
			saveHighScore();
		}
	}
	else if (!enemy->getIsAlive()) {
		state = new DeathState(rm, this, "You win!");
		if (isHighScore()) {
			saveHighScore();
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
	window.draw(scoreText);
	
}

bool PlayState::isHighScore()
{
	bool isHigher = false;
	std::ifstream inFile;
	inFile.open(rm->getHighScorePath());
	if (!inFile.fail()) {
		int value;
		inFile >> value;
		if (value < player->getScore()) {
			isHigher = true;
		}
	}
	inFile.close();
	return isHigher;
}

void PlayState::saveHighScore()
{
	std::ofstream outFile;
	outFile.open(rm->getHighScorePath());
	if (!outFile.fail()) {
		outFile << player->getScore();
	}
	outFile.close();
}
