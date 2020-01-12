#include "Animator.h"



Animator::Animator(sf::Sprite* sprite, sf::Texture* texture, int columns, int rows)
{
	this->sprite = sprite;
	this->texture = texture;
	maxWidth = static_cast<int>(texture->getSize().x);
	maxHeight = static_cast<int>(texture->getSize().y);
	intRect = { 0,0, maxWidth / columns, maxHeight / rows};
	frameTime = 0.5f;
	isLooping = false;
	currentFrame = 0;
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
		if (isLooping) {
			intRect.left = (intRect.left + intRect.width) % intRect.width;
		}
		else {
			if (intRect.left < (maxWidth - intRect.width)) {
				intRect.left += intRect.width;
			}
		}
		timeBuffer -= sf::seconds(frameTime);
	}
	sprite->setTextureRect(intRect);
}

void Animator::setAnimation(int value, bool isLooping)
{
	if (currentFrame != value) {
		this->isLooping = isLooping;
		intRect.top = value * intRect.height;
		intRect.left = 0;
	}
}
