#include "MenuState.h"
#include "PlayState.h"

MenuState::MenuState(ResourceManager* rm) :
	GameState(rm)
{
	playBox = new Box(rm->getFont(), "play", static_cast<float>(rm->getWindowWidth() / 2), static_cast<float>(rm->getWindowHeight() / 2));
	exitBox = new Box(rm->getFont(), "exit", static_cast<float>(rm->getWindowWidth() / 2), static_cast<float>((rm->getWindowHeight() / 2) + 50.f));

	image.create(rm->getWindowWidth(), rm->getWindowHeight());
	points = 360;
	radius = 0.f;
	count = 0;
	const float PI = 3.1415956f;
	angle = (PI * 2.f) / points;
}


MenuState::~MenuState()
{
	delete playBox;
	delete exitBox;
}

GameState* MenuState::handleEvent(const sf::Event & event)
{
	GameState* state = this;

	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return) {
		state = new PlayState(rm);
		delete this;
	}

	return state;
}

GameState* MenuState::update(const sf::Time & delta)
{
	radius += 1;
	float offset = 0;
	if (radius < 45) {
		for (int i = 0; i < points; ++i) {
			float x = 200.f + radius * cos(offset);
			float y = 200.f - radius * sin(offset);
			image.setPixel(static_cast<int>(x), static_cast<int>(y), sf::Color::Red);
			offset += angle;
		}
	}
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	count = 0;

	return this;
}

void MenuState::render(sf::RenderWindow & window) const
{
	window.draw(sprite);
	playBox->render(window);
	exitBox->render(window);
}
