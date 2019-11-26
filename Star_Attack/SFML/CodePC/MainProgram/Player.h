#pragma once
#include "Entity.h"
class Player :
	public Entity
{
public:
	Player(sf::Texture* texture);
	virtual ~Player();

	void input(const sf::Event &event);
	void rotateTowards(const Entity &other);
	// Inherited via Entity
	virtual void update(sf::Time delta) override;
	virtual void move() override;

private:
	float speed;

	float velX;
	float goalVelX;

	float velY;
	float goalVelY;
private:
	void onKeyDown(sf::Keyboard::Key key);
	void onKeyUp(sf::Keyboard::Key key);
	float lerpMove(float goal, float current, float delta);
};