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
	virtual void moveBullets();
	virtual void shootBullet();
	virtual void setAnimation();
	virtual sf::Sprite& getPlantSprite();
	virtual void setXgridcoordinate(int x);
	virtual void setYgridcoordinate(int y);
	virtual int getXgridcoordinate();
	virtual int getYgridcoordinate();

};