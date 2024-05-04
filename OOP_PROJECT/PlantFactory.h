#pragma once
#include<iostream>
#include "Plant.h"
#include "PeaShooter.h"
#include "SunFlower.h"
#include "WallNut.h"


class PlantFactory
{
private:
	Plant** plants;
	Shooter** peashooters;
	int totalplantTypes; // will be set in default constructor
	int totalPlantObjects;
	// static int eachtypePlants[3]; // current number of plants of each type
public:
	PlantFactory();
	Plant& getPlant(int row, int col);
	Shooter& getShooter(int row, int col);
	// static int getPlantnum(int index);
	

};

