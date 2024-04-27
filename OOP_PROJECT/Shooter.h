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
	virtual void setMaxBullets(int bullets) = 0;
	virtual void setShootingRate(float p_ShootingRate) = 0;
	virtual BulletPea*& getBullet(int index) = 0;
	virtual void moveBullets() = 0;
	virtual void shootBullet() = 0;
	virtual void setAnimation();
	virtual sf::Sprite& getPlantSprite();

};

