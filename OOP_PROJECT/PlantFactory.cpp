#include "PlantFactory.h"

PlantFactory::PlantFactory()
{
	totalplantTypes = 1; // will change later
	plants = new Plant * [totalplantTypes];

	// for the rest of the plants

	for (int i = 0; i < totalplantTypes; ++i) {
		plants[i] = new Plant[10]; // Number of plants for each type
	}

	for (int j = 0; j < 10; ++j) {
		// plants[0][j] = PeaShooter(); // Assuming PeaShooter has a default constructor
	}

	// for the shooters

	peashooters = new Shooter * [totalplantTypes];

	for (int i = 0; i < totalplantTypes; ++i) {
		peashooters[i] = new Shooter[10]; // Number of plants for each type
	}


	for (int j = 0; j < 10; ++j) {
		peashooters[0][j] = PeaShooter(); // Assuming PeaShooter has a default constructor

	}


}

Plant& PlantFactory::getPlant(int row, int col)
{
	return plants[row][col]; 
}

Shooter& PlantFactory::getShooter(int row, int col)
{
	return peashooters[row][col];
}



//int PlantFactory::getPlantnum(int index)
//{
//	return eachtypePlants[index];
//}
	
