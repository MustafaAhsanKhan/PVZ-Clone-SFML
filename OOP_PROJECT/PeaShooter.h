#pragma once
#include<iostream>

#include<SFML/Graphics.hpp>
#include "Shooter.h"

class PeaShooter : public Shooter
{

public:
	PeaShooter();
	virtual void setMaxBullets(int bullets);
	virtual int getMaxBullets();
	virtual void setShootingRate(float p_ShootingRate);
	virtual BulletPea& getBullet(int index);

	// virtual void moveBullets();

	virtual void shootBullet(float deltaTime);
	virtual void setAnimation();
	virtual sf::Sprite& getPlantSprite();
	virtual int getXgridCoordinate();
	virtual int getYgridCoordinate();
	virtual void setXgridCoordinate(int x);
	virtual void setYgridCoordinate(int y);
	~PeaShooter();
};