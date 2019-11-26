#pragma once
#include <SFML/Graphics.hpp>

class Entity : public sf::Drawable
{
public:
	Entity(sf::Texture* texture);
	virtual ~Entity();
	virtual void update(sf::Time delta) = 0;
	virtual void move() = 0;
	void setPosition(float x, float y);
	void setPosition(sf::Vector2f pos);
	sf::FloatRect getBounds() const;
	sf::Vector2f getPosition() const;

	// Inherited via Drawable
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;

protected:
	void moveSprite(sf::Vector2f dir, float speed);
	void moveSprite(float velX, float velY);
	void rotateSprite(float angle);
private:
	sf::Sprite sprite;



};

