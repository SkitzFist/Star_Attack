#include "Animator.h"



Animator::Animator(sf::Sprite* sprite, sf::Texture* texture, int columns, int rows)
{
	this->sprite = sprite;
	this->texture = texture;
	int width = static_cast<int>(texture->getSize().x / columns);
	int height = static_cast<int>(texture->getSize().y / rows);
	intRect = { 0,0, width, height};

	frameTime = 0.2f;
	
}


Animator::~Animator()
{
}

void Animator::update(sf::Time delta)
{	
	static sf::Time timeBuffer = sf::Time::Zero;
	timeBuffer += delta;

	while ( timeBuffer.asSeconds() > frameTime)
	{
		intRect.left = (intRect.left + intRect.width) % texture->getSize().x;
		
		timeBuffer -= sf::seconds(frameTime);
	}
	sprite->setTextureRect(intRect);
}
