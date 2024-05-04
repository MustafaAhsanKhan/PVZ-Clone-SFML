#pragma once
#include "Zombie.h"
class FootballZombie : public Zombie
{
public:
	FootballZombie();
	sf::Sprite& getZombieSprite();
	virtual int getXgridCoordinate();
	virtual int getYgridCoordinate();
	virtual void setXgridCoordinate(float);
	virtual void setYgridCoordinate(float);
	virtual float getx_pos();
	virtual float gety_pos();
	virtual void setx_pos(float);
	virtual void sety_pos(float);
	virtual void damagePlant(Plant&);
	virtual int getZombieHealth();
	virtual void setAnimation();
	virtual void moveZombie(float deltaTime);
};