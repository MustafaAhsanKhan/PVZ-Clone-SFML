#pragma once
#include "Zombie.h"

class BackupDancerZombie : public Zombie
{
public:
	BackupDancerZombie();
	sf::Sprite& getZombieSprite();
	virtual int getXgridCoordinate();
	virtual int getYgridCoordinate();
	virtual void setisEating(bool iseating);
	virtual void setXgridCoordinate(float);
	virtual void setYgridCoordinate(float);
	virtual float getx_pos();
	virtual float gety_pos();
	virtual bool getExists();
	virtual void setx_pos(float);
	virtual void sety_pos(float);
	virtual void setExists(bool);
	virtual void damagePlant(Plant&);
	virtual int getZombieHealth();
	virtual void setAnimation();
	virtual void moveZombie(float deltaTime);
	virtual void operator-=(int damage);
};

