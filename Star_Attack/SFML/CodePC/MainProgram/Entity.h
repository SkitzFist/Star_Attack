#pragma once
#include "GameObject.h"
#include "Animator.h"

class Entity : public GameObject
{
public:
	Entity(sf::Texture* texture, int spriteColumns, int spriteRows);
	virtual ~Entity();
	virtual void takeDamage() = 0;
	bool getIsAlive() const;
	

protected:

	virtual void update(sf::Time delta) override;
	virtual void updateObject(sf::Time delta) = 0;
	virtual void move() override;
	virtual void moveObject() = 0;
	void setIsAlive(bool isAlive);
	int getHealth() const;
	void addToHealth(int value);
	Animator* animator;
private:
	bool isAlive;
	int health;
	
};

