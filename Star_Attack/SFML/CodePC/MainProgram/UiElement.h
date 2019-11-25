#pragma once
#include <SFML/Graphics.hpp>

class UiElement : public sf::Drawable
{
public:
	UiElement();
	virtual ~UiElement();

	virtual void update(sf::Time delta) = 0;
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
};

