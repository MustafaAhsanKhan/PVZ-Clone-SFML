#include "PlantFactory.h"

PlantFactory::PlantFactory()
{
	totalplantTypes = 2; // will change later
	totalPlantObjects = 50;  // Max number of plants for a single type
	plants = new Plant * [totalplantTypes];
	// for the shooters
	shooters = new Shooter * [totalplantTypes];
	shooters[0] = new PeaShooter[totalPlantObjects];  
	shooters[1] = new SnowPea[totalPlantObjects];
}

Plant& PlantFactory::getPlant(int row, int col)
{
	return plants[row][col];  // return the plant at the given row and column
}

Shooter& PlantFactory::getShooter(int row, int col)
{
	return shooters[row][col];  // return the shooter at the given row and column
}
