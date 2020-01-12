#include "Box.h"
#include <iostream>


Box::Box( sf::Font* font, std::string string, float x, float y)
{
	//config
	boxOffset = 10.f;
	outlineThickness = 2.0f;
	text.setFillColor(sf::Color::White);

	box.setFillColor(sf::Color::Black);
	box.setOutlineColor(sf::Color::Green);
	box.setOutlineThickness(0);

	//setup
	text.setFont(*font);
	text.setCharacterSize(35);
	text.setString(string);
	float width = text.getGlobalBounds().width;
	float height = text.getGlobalBounds().height;
	box.setSize(sf::Vector2f(width + boxOffset, height + (boxOffset)));
	box.setOrigin(box.getSize().x / 2, box.getSize().y / 2);

	setPosition(x, y);
}


Box::~Box()
{
}

void Box::setPosition(float x, float y)
{
	box.setPosition(x, y);
	text.setPosition( 
		(box.getPosition().x - (box.getSize().x / 2)) + (boxOffset / 2), 
		(box.getPosition().y - (box.getSize().y /2)) - (boxOffset /2)
	);
}

void Box::render(sf::RenderWindow & window)
{
	window.draw(box);
	window.draw(text);
}

void Box::markBox()
{
	box.setOutlineThickness(outlineThickness);
}

void Box::unmarkBox()
{
	box.setOutlineThickness(0.f);
}
