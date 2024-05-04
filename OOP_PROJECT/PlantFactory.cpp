#include "PlantFactory.h"

PlantFactory::PlantFactory()
{
	totalplantTypes = 1; // will change later
	totalPlantObjects = 50;  // Max number of plants for a single type
	plants = new Plant * [totalplantTypes];

	// for the rest of the plants

	for (int i = 0; i < totalplantTypes; ++i) {
		plants[i] = new Plant[10]; // Number of plants for each type
	}

	// for the shooters
	peashooters = new Shooter * [totalplantTypes];

	peashooters[0] = new PeaShooter[totalPlantObjects];  
	

}

Plant& PlantFactory::getPlant(int row, int col)
{
	return plants[row][col];  // return the plant at the given row and column
}

Shooter& PlantFactory::getShooter(int row, int col)
{
	return peashooters[row][col];  // return the shooter at the given row and column
}



//int PlantFactory::getPlantnum(int index)
//{
//	return eachtypePlants[index];
//}
	
