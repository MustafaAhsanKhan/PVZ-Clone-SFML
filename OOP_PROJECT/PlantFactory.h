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
	int totalplantTypes; // will be set in default constructor
	// static int eachtypePlants[3]; // current number of plants of each type
public:
	PlantFactory();
	Plant& getPlant(int row, int col);
	
	// static int getPlantnum(int index);
	

};

