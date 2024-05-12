#pragma once
#include "Shooter.h"

class PeaShooter : public Shooter
{

public:
	PeaShooter();
	virtual int getPlantHealth();
	virtual int getMaxBullets();
	virtual Bullet& getBullet(int index);
	virtual void setExists(bool ex);
	virtual bool exists();
	virtual void shootBullet(float deltaTime);
	virtual void Act();
	virtual sf::Sprite& getPlantSprite();
	virtual int getXgridCoordinate();
	virtual int getYgridCoordinate();
	virtual void setXgridCoordinate(int x);
	virtual void setYgridCoordinate(int y);
	virtual void operator-=(int damage);
	virtual void setSunClock();
	virtual Sun*& getSun();
	virtual void drawSun(sf::RenderWindow& window, int &sunsNum, sf::Sound& sound) {}
	sf::Clock& getShootingRateClock();
	~PeaShooter();
};