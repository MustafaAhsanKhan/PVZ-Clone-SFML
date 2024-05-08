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
	virtual BulletPea& getBullet(int index) = 0;
	virtual int getMaxBullets() = 0;
	virtual void setExists(bool ex) = 0; // sets existence of the plant
	virtual bool exists() = 0; // checks if it exists (returns plantExists data member)
	virtual void shootBullet(float deltaTime) = 0;
	virtual void setAnimation() = 0;
	virtual sf::Sprite& getPlantSprite() = 0;
	virtual void setXgridCoordinate(int x) = 0;
	virtual void setYgridCoordinate(int y) = 0;
	virtual int getXgridCoordinate() = 0;
	virtual int getYgridCoordinate() = 0;
	virtual ~Shooter() { delete[] bullets; }

};