#pragma once
#include "Plant.h"
class WallNut : public Plant
{
public:
	WallNut();
	virtual void setExists(bool ex); // sets existence of the plant
	virtual bool exists();
	virtual void Act();
	virtual sf::Sprite& getPlantSprite();
	virtual void setXgridCoordinate(int x);
	virtual void setYgridCoordinate(int y);
	virtual int getXgridCoordinate();
	virtual int getYgridCoordinate();
};