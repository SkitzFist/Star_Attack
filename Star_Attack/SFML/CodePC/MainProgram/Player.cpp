#include "Player.h"


Player::Player(sf::Texture* texture, BulletHandler* bh, ResourceManager* rm, Enemy* enemy) :
	Entity(texture),
	isShooting(false),
	enemy(enemy)
{
	//config
	float startX = 300.f;
	float startY = 300.f;
	speed = 4.5f;
	float timeBetweenShots = 0.3f;

	//Init
	setPosition(startX, startY);
	setSpriteScale(0.5f);
	velX = 0;
	velY = 0;
	goalVelX = 0;
	goalVelY = 0;
	weapon = new PlayerWeapon(timeBetweenShots, rm, bh);
}

Player::~Player()
{
	delete weapon;
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

void Player::boundToWindow(ResourceManager * rm)
{
	if (getPosition().x - getBounds().width / 2 < 0) {
		setPosition(0 + getBounds().width / 2, getPosition().y);
	}
	else if (getPosition().x + getBounds().width / 2 > rm->getWindowWidth()) {
		setPosition(rm->getWindowWidth() - getBounds().width / 2, getPosition().y);
	}

	if (getPosition().y - getBounds().height / 2 < 0) {
		setPosition(getPosition().x, 0 + getBounds().height / 2);
	}
	else if (getPosition().y + getBounds().height / 2 > rm->getWindowHeight()) {
		setPosition(getPosition().x, rm->getWindowHeight() - getBounds().height / 2);
	}
}

void Player::updateObject(sf::Time delta)
{
	engageMove(delta);
	weapon->update(delta);
	if (weapon->getTimeLeft() <= 0 && isShooting) {
		shoot();
	}
}

void Player::moveObject()
{
	moveSprite(velX, velY);
}

void Player::takeDamage()
{
}

void Player::onKeyDown(sf::Keyboard::Key key)
{
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

	if (key == sf::Keyboard::Space) {
		isShooting = true;
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

	if (key == sf::Keyboard::Space) {
		isShooting = false;
	}
}

void Player::engageMove(sf::Time delta)
{
	velY = lerpMove(goalVelY, velY, (float)delta.asMicroseconds());
	velX = lerpMove(goalVelX, velX, (float)delta.asMicroseconds());
	move();
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

void Player::shoot()
{
	sf::Vector2f delta = {
			enemy->getPosition().x - this->getPosition().x,
			enemy->getPosition().y - this->getPosition().y
	};
	float magnitude = sqrt(delta.x * delta.x + delta.y * delta.y);

	sf::Vector2f dir = {
		delta.x / magnitude,
		delta.y / magnitude
	};
	weapon->fire(getPosition(), dir);
}