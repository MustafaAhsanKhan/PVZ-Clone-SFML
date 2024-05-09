#pragma once
#include "Plant.h"
class normalPlant : public Plant
{
public:
	void setExists(bool ex) = 0; // sets existence of the plant
	bool exists() = 0; // checks if it exists (returns plantExists data member)	
	void setAnimation() = 0;
	sf::Sprite& getPlantSprite() = 0;
	void setXgridCoordinate(int x) = 0;
	void setYgridCoordinate(int y) = 0;
	int getXgridCoordinate() = 0;
	int getYgridCoordinate() = 0;

};

