#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Box
{
public:
	Box(sf::Font* font, std::string text, float x, float y);
	~Box();

	void movePosition(float x, float y);
	void render(sf::RenderWindow &window);

private:
	sf::Text text;
	sf::RectangleShape box;
	float boxOffset;
};

