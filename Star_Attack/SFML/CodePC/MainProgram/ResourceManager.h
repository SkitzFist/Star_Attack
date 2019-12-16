#pragma once
#include <SFML/Graphics.hpp>
#include <iostream> //Todo: delete this
class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();

	int getWindowWidth() const;
	int getWindowHeight() const;

	sf::Font* getFont();
	sf::Texture* getPlayerTexture();
	sf::Texture* getBossTexture();
	sf::Texture* getWhiteBallTexture();
	sf::Texture* getRedBallTexture();
	sf::Texture* getBgrTexture();

	void setup(int windowWidth, int windowHeight);

private:
	int windowWidth;
	int windowHeight;
	//UI
	sf::Font* font;
	sf::Texture* bgr;

	//Player
	sf::Texture* playerTexture;

	//Boss
	sf::Texture* BossTexture;

	//Projectiles
	sf::Texture* whiteBallTexture;
	sf::Texture* redBallTexture;
};

