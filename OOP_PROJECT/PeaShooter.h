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

	virtual void shootBullet();
	virtual void setAnimation();
	virtual sf::Sprite& getPlantSprite();
	virtual int getXgridcoordinate();
	virtual int getYgridcoordinate();
	virtual void setXgridcoordinate(int x);
	virtual void setYgridcoordinate(int y);

	~PeaShooter();
};