#pragma once
#include "Entity.h"
#include "ResourceManager.h"
class Bullet :
	public GameObject
{
public:
	Bullet(sf::Texture* texture);
	virtual ~Bullet();
	int getId() const;
	void setup(sf::Vector2f dir);

	// Inherited via Entity
	virtual void update(sf::Time delta) override;
	virtual void move() override;

private:
	sf::Vector2f dir;
	int id;
	float speed;
};

