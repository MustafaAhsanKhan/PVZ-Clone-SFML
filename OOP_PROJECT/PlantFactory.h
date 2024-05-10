#pragma once
#include<iostream>
#include "Plant.h"
#include "PeaShooter.h"
#include "SunFlower.h"
#include "WallNut.h"
#include "Cherrybomb.h"
#include "Repeater.h"
#include "SnowPea.h"
#include "FumeShroom.h"




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
	~PlantFactory();
	

};

