#include "Player.h"



Player::Player(sf::Texture* texture) :
	Entity(texture)
{
	setPosition(300.f, 300.f);

	speed = 10.5f;
	velX = 0;
	velY = 0;

	goalVelX = 0;
	goalVelY = 0;
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

void Player::rotateTowards(const Entity & other)
{
	sf::Vector2f dist = { 
		other.getPosition().x - this->getPosition().x,
		other.getPosition().y - this->getPosition().y
	};
	float angleRadian = atan2(dist.y, dist.x);

	rotateSprite(angleRadian);
}

void Player::update(sf::Time delta)
{
	velY = lerpMove(goalVelY, velY, (float)delta.asMicroseconds());
	velX = lerpMove(goalVelX, velX, (float)delta.asMicroseconds());
	move();
}

void Player::move()
{
	moveSprite(velX, velY);
}

void Player::onKeyDown(sf::Keyboard::Key key)
{
	//if (key == sf::Keyboard::Up) {
	//	goalVelY = -speed;
	//}
	//else if (key == sf::Keyboard::Down) {
	//	goalVelY = speed;
	//}

	//if (key == sf::Keyboard::Right) {
	//	goalVelX = speed;
	//}
	//else if (key == sf::Keyboard::Left) {
	//	goalVelX = -speed;
	//}
	switch (key)
	{
	case sf::Keyboard::Up:
		goalVelY = -speed;
		break;
	case sf::Keyboard::Down:
		goalVelY = speed;
		break;
	default:
		break;
	}

	switch (key)
	{
	case sf::Keyboard::Right:
		goalVelX = speed;
		break;
	case sf::Keyboard::Left:
		goalVelX = -speed;
		break;
	default:
		break;
	}
}

void Player::onKeyUp(sf::Keyboard::Key key)
{
	if (key == sf::Keyboard::Up && !sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ||
		key == sf::Keyboard::Down && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		goalVelY = 0;
	}
	else if (key == sf::Keyboard::Up && sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		goalVelY = speed;
	}
	else if (key == sf::Keyboard::Down && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		goalVelY = -speed;
	}

	if (key == sf::Keyboard::Right && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
		key == sf::Keyboard::Left && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		goalVelX = 0;
	}
	else if (key == sf::Keyboard::Left && sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		goalVelX = speed;
	}
	else if (key == sf::Keyboard::Right && sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		goalVelX = -speed;
	}
}

float Player::lerpMove(float goal, float current, float delta)
{
	float difference = goal - current;

	if (difference > delta) {
		return current + delta;
	}
	else if (difference < -delta) {
		return current - delta;
	}
	return goal;
}
