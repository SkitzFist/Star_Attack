#include "Player.h"



Player::Player(sf::Texture* texture):
	Entity(texture)
{
	setPosition(300.f, 300.f);

	speed = 6.f;
	velX = 0;
	velY = 0;

	goalVelX = 0;
	goalVelY = 0;
	isLerpMove = false;
}


Player::~Player()
{
}

void Player::input(const sf::Event & event)
{
	switch (event.type)
	{
	case sf::Event::KeyPressed:
		onKeyDown(event.key.code);
		break;
	case sf::Event::KeyReleased:
		onKeyUp(event.key.code);
		break;
	default:
		break;
	}
}

void Player::update(sf::Time delta)
{
	if (isLerpMove) {
		velY = lerpMove(goalVelY, velY, delta.asSeconds());
		velX = lerpMove(goalVelX, velX, delta.asSeconds());
	}
	move();
}

void Player::move()
{
	moveSprite(velX, velY);
}

void Player::onKeyDown(sf::Keyboard::Key key)
{
	switch (key)
	{
	case sf::Keyboard::Up:
		if (isLerpMove) {
			goalVelY = -speed;
		}
		else {
			velY = -speed;
		}
		break;
	case sf::Keyboard::Down:
		if (isLerpMove) {
			goalVelY = speed;
		}
		else {
			velY = speed;
		}
		break;
	default:
		break;
	}

	switch (key)
	{
	case sf::Keyboard::Right:
		if (isLerpMove) {
			goalVelX = speed;
		}
		else {
			velX = speed;
		}
		break;
	case sf::Keyboard::Left:
		if (isLerpMove) {
			goalVelX = -speed;
		}
		else {
			velX = -speed;
		}
		break;
	case sf::Keyboard::Space:
		if (!isLerpMove) {
			isLerpMove = true;
		}
		else {
			isLerpMove = false;
		}
	default:
		break;
	}
}

void Player::onKeyUp(sf::Keyboard::Key key)
{
	if (key == sf::Keyboard::Up && !sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ||
		key == sf::Keyboard::Down && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		if (isLerpMove) {
			goalVelY = 0;
		}
		else {
			velY = 0;
		}

	}
	else if (key == sf::Keyboard::Up && sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		if (isLerpMove) {
			goalVelY = speed;
		}
		else {
			velY = speed;
		}

	}
	else if (key == sf::Keyboard::Down && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		if (isLerpMove) {
			goalVelY = -speed;
		}
		else {
			velY = -speed;
		}	
	}

	if (key == sf::Keyboard::Right && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
		key == sf::Keyboard::Left && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		if (isLerpMove) {
			goalVelX = 0;
		}
		else {
			velX = 0;
		}

	}
	else if (key == sf::Keyboard::Left && sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		if (isLerpMove) {
			goalVelX = speed;
		}
		else {
			velX = speed;
		}

	}
	else if (key == sf::Keyboard::Right && sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		if (isLerpMove) {
			goalVelX = -speed;
		}
		else {
			velX = -speed;
		}
	
	}
}

float Player::lerpMove(float goal, float current, float delta)
{
	float difference = goal - current;

	if (difference > delta) {
		return current + delta;
	}
	if (difference < -delta) {
		return current - delta;
	}
	return goal;
}
