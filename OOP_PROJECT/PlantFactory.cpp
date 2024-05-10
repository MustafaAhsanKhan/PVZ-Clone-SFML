#include "PlantFactory.h"

PlantFactory::PlantFactory() : MAX_PLANTS(50)
{
	totalShooterplantTypes = 2; // will change later
	totalNormalPlantTypes = 2;

	plants = new Plant * [totalNormalPlantTypes];
	plants[0] = new SunFlower[MAX_PLANTS];
	plants[0][1].Act(); // problem in this part of the code
	shooterPlants = new Shooter * [totalShooterplantTypes];
	shooterPlants[0] = new PeaShooter[MAX_PLANTS];
	shooterPlants[1] = new SnowPea[MAX_PLANTS];
	shooterPlants[0][0].Act();
}

Plant& PlantFactory::getNormalPlant(int row, int col)
{
	return plants[row][col];  // return the plant at the given row and column
}

Shooter& PlantFactory::getShooter(int row, int col)
{
	return shooterPlants[row][col];  // return the shooter at the given row and column
}
