#pragma once
#include "Entity.h"
#include "ResourceManager.h"
class Bullet :
	public GameObject
{
public:
	Bullet(sf::Texture* texture);
	virtual ~Bullet();
	void setDirection(sf::Vector2f dir);
	bool isColliding(const GameObject &go);
	bool getCanDelete() const;
	// Inherited via Entity
	virtual void update(sf::Time delta) override;
	virtual void updateBullet(sf::Time delta) = 0;
	virtual void move() override;

protected:
	sf::Vector2f dir;
	bool canDelete;

private:
	float speed;

};

