#include "Plant.h"
#include <SFML/Graphics.hpp>

Plant::Plant()
{
	
}

void Plant::setAnimation()
{

}

sf::Sprite& Plant::getPlantSprite()
{
	return plantSprite;
}


void Plant::setXgridcoordinate(int x)
{
	Xgridcoordinate = x;
}
void Plant::setYgridcoordinate(int y)
{
	Ygridcoordinate = y;
}
int Plant::getXgridcoordinate()
{
	return Xgridcoordinate;
}
int Plant::getYgridcoordinate()
{
	return Ygridcoordinate;
}
