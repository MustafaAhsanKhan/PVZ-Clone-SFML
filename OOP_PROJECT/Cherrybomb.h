#pragma once
#include "Plant.h"
class Cherrybomb : public Plant
{
public:
	Cherrybomb();
	virtual int getPlantHealth();
	virtual void setExists(bool ex); // sets existence of the plant
	virtual bool exists();
	virtual void Act();
	virtual sf::Sprite& getPlantSprite();
	virtual void setXgridCoordinate(int x);
	virtual void setYgridCoordinate(int y);
	virtual int getXgridCoordinate();
	virtual int getYgridCoordinate();
	virtual void operator-=(int damage);
	virtual void setSunClock();
	virtual Sun*& getSun();
	virtual void drawSun(sf::RenderWindow& window, int &ssunsNum, sf::Sound& sound) {}
};

