#pragma once
#include "Entity.h"
#include "PlayerWeapon.h"
#include "Enemy.h"
#include "BulletHandler.h"

class Player :
	public Entity
{
public:
	Player(sf::Texture* texture, BulletHandler* bh, ResourceManager* rm, Enemy* enemy);
	virtual ~Player();

	
	void input(const sf::Event &event);
	void rotateTowards(const Entity &other);
	void boundToWindow(ResourceManager* rm);
	// Inherited via Entity
	virtual void updateObject(sf::Time delta) override;
	virtual void moveObject() override;
	virtual void takeDamage();
private:
	float speed;

	float velX;
	float goalVelX;

	float velY;
	float goalVelY;

	Enemy* enemy;

	PlayerWeapon* weapon;
	bool isShooting;

	const int IDLE = 0;
	const int TURN_LEFT = 1;
	const int TURN_RIGHT = 2;

private:
	void onKeyDown(sf::Keyboard::Key key);
	void onKeyUp(sf::Keyboard::Key key);
	void engageMove(sf::Time delta);
	float lerpMove(float goal, float current, float delta);
	void shoot();

	sf::Keyboard::Key up;
	sf::Keyboard::Key down;
	sf::Keyboard::Key right;
	sf::Keyboard::Key left;
};