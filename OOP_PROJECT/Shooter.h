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
	virtual BulletPea& getBullet(int index) = 0;
	virtual int getMaxBullets() = 0;
	// virtual void moveBullets();

	virtual void shootBullet(float deltaTime) = 0;
	virtual void setAnimation() = 0;
	virtual sf::Sprite& getPlantSprite() = 0;
	virtual void setXgridCoordinate(int x) = 0;
	virtual void setYgridCoordinate(int y) = 0;
	virtual int getXgridCoordinate() = 0;
	virtual int getYgridCoordinate() = 0;
	virtual ~Shooter() { delete[] bullets; }

};