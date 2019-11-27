#pragma once
#include <SFML/Graphics.hpp>
#include <iostream> //Todo: delete this
class ResourceManager
{
public:
	static const int WINDOW_WIDTH = 800;
	static const int WINDOW_HEIGHT = 600;
public:
	ResourceManager();
	~ResourceManager();

	sf::Font* getFont();
	sf::Texture* getPlayerTexture();
	sf::Texture* getBossTexture();

	void setup();

private:

	//UI
	sf::Font* font;

	//Player
	sf::Texture* playerTexture;


	//Boss
	sf::Texture* BossTexture;
};

