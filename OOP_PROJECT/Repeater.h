#pragma once
#include "Shooter.h"
class Repeater :public Shooter
{
public:
	Repeater();
	virtual int getMaxBullets();
	virtual Bullet& getBullet(int index);
	virtual void setExists(bool ex);
	virtual bool exists();
	virtual void shootBullet(float deltaTime);
	virtual void Act();
	virtual sf::Sprite& getPlantSprite();
	virtual int getXgridCoordinate();
	virtual int getYgridCoordinate();
	virtual void setXgridCoordinate(int x);
	virtual void setYgridCoordinate(int y);
	~Repeater();
};

