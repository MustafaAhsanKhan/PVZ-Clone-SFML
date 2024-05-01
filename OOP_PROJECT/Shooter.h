#pragma once
#include "Plant.h"
#include "BulletPea.h"

class Shooter : public Plant
{
protected:
	int MAX_BULLETS;
	sf::Clock ShootingRateClock;
	float ShootingRate;
	BulletPea* bullets;
public:
	virtual void setMaxBullets(int bullets);
	virtual void setShootingRate(float p_ShootingRate);
	virtual BulletPea& getBullet(int index);
	virtual int getMaxBullets();
	// virtual void moveBullets();

	virtual void shootBullet(float deltaTime);
	virtual void setAnimation();
	virtual sf::Sprite& getPlantSprite();
	virtual void setXgridCoordinate(int x);
	virtual void setYgridCoordinate(int y);
	virtual int getXgridCoordinate();
	virtual int getYgridCoordinate();

};