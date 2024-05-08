#pragma once
#include<iostream>
#include "Plant.h"
#include "PeaShooter.h"
#include "SnowPea.h"
#include "SunFlower.h"
#include "WallNut.h"


class PlantFactory
{
private:
	Plant** plants;
	Shooter** shooterPlants;
	int totalShooterplantTypes; // will be set in default constructor
	int totalNormalPlantTypes; // will be set in default constructor
	const int MAX_PLANTS;
public:
	PlantFactory();
	Plant& getNormalPlant(int row, int col);
	Shooter& getShooter(int row, int col);
	

};

