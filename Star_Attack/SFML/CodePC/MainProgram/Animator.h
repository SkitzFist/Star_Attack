#pragma once
#include <SFML/Graphics.hpp>
class Animator
{
public:
	Animator(sf::Sprite* sprite,sf::Texture* texture, int columns, int rows);
	~Animator();

	void update(sf::Time delta);
	void setAnimation(int value, bool isLooping);

private:
	Animator() = delete;
	sf::IntRect intRect;
	sf::Sprite* sprite;
	sf::Texture* texture;
	float frameTime;
	bool isLooping;

	int maxWidth;
	int maxHeight;
};

