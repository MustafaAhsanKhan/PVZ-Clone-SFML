#pragma once
#include<iostream>

#include<SFML/Graphics.hpp>
#include "Shooter.h"

class PeaShooter : public Shooter
{

public:
	PeaShooter();
	virtual int getMaxBullets();
	virtual BulletPea& getBullet(int index);
	virtual void setExists(bool ex);
	virtual bool exists();
	virtual void shootBullet(float deltaTime);
	virtual void Act();
	virtual sf::Sprite& getPlantSprite();
	virtual int getXgridCoordinate();
	virtual int getYgridCoordinate();
	virtual void setXgridCoordinate(int x);
	virtual void setYgridCoordinate(int y);
	~PeaShooter();
};