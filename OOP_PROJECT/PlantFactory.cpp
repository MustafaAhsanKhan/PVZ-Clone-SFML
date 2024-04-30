#include "PlantFactory.h"

PlantFactory::PlantFactory()
{
	totalplantTypes = 2; // will change later
	plants = new Plant * [totalplantTypes];
	plants[0] = new PeaShooter [5];
	plants[1] = new SunFlower [5];
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
	
