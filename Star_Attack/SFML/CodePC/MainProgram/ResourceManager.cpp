#include "ResourceManager.h"


ResourceManager::ResourceManager()
{

}

ResourceManager::~ResourceManager()
{
	delete font;
	delete playerTexture;
	delete BossTexture;
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

void ResourceManager::setup()
{
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
}

