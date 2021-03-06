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

	sf::Image* getBgrImage();
	sf::Image* getBgrImageOrig();
	sf::Texture* getBgrTexture();
	sf::Sprite* getBgrSprite();

	void resetBgrImage();

	void setupBgrImage(sf::Image* image);
	void setup(int windowWidth, int windowHeight);

private:
	int windowWidth;
	int windowHeight;
	//UI
	
	sf::Font* font;

	//bgrImage
	sf::Image* bgrImageOrig;
	sf::Image* bgrImage;
	sf::Texture* bgrTexture;
	sf::Sprite* bgrSprite;

	//Player
	sf::Texture* playerTexture;

	//Boss
	sf::Texture* BossTexture;

	//Projectiles
	sf::Texture* whiteBallTexture;
	sf::Texture* redBallTexture;
};

