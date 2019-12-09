#include "ResourceManager.h"


ResourceManager::ResourceManager()
{

}

ResourceManager::~ResourceManager()
{
	delete font;
	delete playerTexture;
	delete BossTexture;
	delete whiteBallTexture;
}
int ResourceManager::getWindowWidth() const
{
	return windowWidth;
}
int ResourceManager::getWindowHeight() const
{
	return windowHeight;
}
sf::Font * ResourceManager::getFont()
{
	return font;
}

sf::Texture * ResourceManager::getPlayerTexture()
{
	return playerTexture;
}

sf::Texture * ResourceManager::getBossTexture()
{
	return BossTexture;
}

sf::Texture * ResourceManager::getWhiteBallTexture()
{
	return whiteBallTexture;
}

void ResourceManager::setup(int windowWidth, int windowHeight)
{
	this->windowWidth = windowWidth;
	this->windowHeight = windowHeight;

	font = new sf::Font();
	if (!font->loadFromFile("../Fonts/zian.ttf")) {
		throw std::runtime_error("Could not load font");
	}
	playerTexture = new sf::Texture();
	if (!playerTexture->loadFromFile("../Sprites/player.png")) {
		throw std::runtime_error("Could not load player texture");
	}
	BossTexture = new sf::Texture();
	if (!BossTexture->loadFromFile("../Sprites/boss.png")) {
		throw std::runtime_error("Could not load boss texture");
	}
	whiteBallTexture = new sf::Texture();
	if (!whiteBallTexture->loadFromFile("../Sprites/ball16.png")) {
		throw std::runtime_error("Could not load white ball texture");
	}
}

