#pragma once
#include "Plant.h"
class SunFlower : public Plant
{
public:
	SunFlower();
	virtual void setExists(bool ex); // sets existence of the plant
	virtual bool exists();
	virtual void setAnimation();
	virtual sf::Sprite& getPlantSprite();
	virtual void setXgridCoordinate(int x);
	virtual void setYgridCoordinate(int y);
	virtual int getXgridCoordinate();
	virtual int getYgridCoordinate();
};