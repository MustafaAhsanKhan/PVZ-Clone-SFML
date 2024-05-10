#include "PlantFactory.h"

PlantFactory::PlantFactory() : MAX_PLANTS(50)
{
	totalShooterplantTypes = 4; // will change later
	totalNormalPlantTypes = 3;

	plants = new Plant * [totalNormalPlantTypes];
	plants[0] = new SunFlower[MAX_PLANTS];
	plants[1] = new WallNut[MAX_PLANTS];
	plants[2] = new Cherrybomb[MAX_PLANTS];

	shooterPlants = new Shooter * [totalShooterplantTypes];
	shooterPlants[0] = new PeaShooter[MAX_PLANTS];
	shooterPlants[1] = new Repeater[MAX_PLANTS];
	shooterPlants[2] = new SnowPea[MAX_PLANTS];
	shooterPlants[3] = new FumeShroom[MAX_PLANTS];
}

Plant& PlantFactory::getNormalPlant(int row, int col)
{
	return plants[row][col];  // return the plant at the given row and column
}

Shooter& PlantFactory::getShooter(int row, int col)
{
	return shooterPlants[row][col];  // return the shooter at the given row and column
}

PlantFactory::~PlantFactory()
{
	for (int i = 0; i < totalShooterplantTypes; i++)
	{
		delete[] shooterPlants[i]; 
	}

	for (int i = 0; i < totalNormalPlantTypes; i++)
	{
		delete[] plants[i];
	}
	delete[] shooterPlants;
	delete[] plants;
}