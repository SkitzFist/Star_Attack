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
	delete redBallTexture;

	delete bgrImage;
	delete bgrImageOrig;
	delete bgrTexture;
	delete bgrSprite;

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

sf::Texture * ResourceManager::getRedBallTexture()
{
	return redBallTexture;
}

sf::Image * ResourceManager::getBgrImage()
{
	return bgrImage;
}

sf::Image * ResourceManager::getBgrImageOrig()
{
	return bgrImageOrig;
}

sf::Texture * ResourceManager::getBgrTexture()
{
	return bgrTexture;
}

sf::Sprite * ResourceManager::getBgrSprite()
{
	return bgrSprite;
}

void ResourceManager::resetBgrImage()
{
	for (unsigned int x = 0; x < bgrImage->getSize().x; ++x) {
		for (unsigned int y = 0; y < bgrImage->getSize().y; ++y) {
			sf::Color color = bgrImageOrig->getPixel(x, y);
			bgrImage->setPixel(x,y,color);
		}
	}
	bgrTexture->loadFromImage(*bgrImage);
}

void ResourceManager::setupBgrImage(sf::Image * image)
{
	this->bgrImageOrig = new sf::Image(*image);
	this->bgrImage = image;
	bgrSprite = new sf::Sprite();
	bgrTexture = new sf::Texture();

	bgrTexture->loadFromImage(*bgrImage);
	bgrSprite->setTexture(*bgrTexture);

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
	redBallTexture = new sf::Texture();
	if (!redBallTexture->loadFromFile("../Sprites/Curseless.png")) {
		throw std::runtime_error("Could not load white ball texture");
	}
}

