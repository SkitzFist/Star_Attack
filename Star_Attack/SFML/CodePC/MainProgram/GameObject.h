#pragma once
#include <SFML/Graphics.hpp>


class GameObject : public sf::Drawable
{
public:
	GameObject();
	~GameObject();
	void setTexture(sf::Texture* texture);
	virtual void update(sf::Time delta) = 0;
	virtual void move() = 0;
	void setPosition(float x, float y);
	void setPosition(sf::Vector2f pos);
	sf::FloatRect getBounds() const;
	sf::Vector2f getPosition() const;
	void moveSprite(sf::Vector2f dir, float speed);
	void moveSprite(float velX, float velY);
	void rotateSprite(float angle);

	// Inherited via Drawable
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;


private:
	sf::Sprite sprite;

};

