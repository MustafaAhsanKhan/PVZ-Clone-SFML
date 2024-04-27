#pragma once
#include<iostream>

#include<SFML/Graphics.hpp>
#include "Shooter.h"

class PeaShooter : public Shooter
{

public:
	PeaShooter() {}
	virtual void setMaxBullets(int bullets);
	virtual void setShootingRate(float p_ShootingRate);
	virtual BulletPea*& getBullet(int index);
	virtual void moveBullets();
	virtual void shootBullet();
	virtual void setAnimation();
	virtual sf::Sprite& getPlantSprite();
};