#pragma once
#include "Shooter.h"
class SnowPea : public Shooter
{
public:
	SnowPea();
	virtual Bullet& getBullet(int index);
	virtual int getMaxBullets();
	virtual void setExists(bool ex); 
	virtual bool exists(); 
	virtual void shootBullet(float deltaTime);
	virtual void Act();
	virtual sf::Sprite& getPlantSprite();
	virtual void setXgridCoordinate(int x);
	virtual void setYgridCoordinate(int y);
	virtual int getXgridCoordinate();
	virtual int getYgridCoordinate();
	~SnowPea();
};

