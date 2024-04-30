#include "PlantFactory.h"

PlantFactory::PlantFactory()
{
	totalplantTypes = 1; // will change later
	plants = new Plant * [totalplantTypes];

	for (int i = 0; i < totalplantTypes; ++i) {
		plants[i] = new Plant[5];
	}
	for (int j = 0; j < 5; ++j) {
		plants[0][j] = PeaShooter(); // Assuming PeaShooter has a default constructor
	}

	// plants[0][1].getPlantSprite().setPosition(190, 199);
	
	// plants[1] = new SunFlower [5];
	// 2 rows and 5 column arrays
}

Plant& PlantFactory::getPlant(int row, int col)
{
	return plants[row][col]; 
}

//int PlantFactory::getPlantnum(int index)
//{
//	return eachtypePlants[index];
//}
	
