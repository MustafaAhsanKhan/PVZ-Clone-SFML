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


void Plant::setXgridCoordinate(int x)
{
	XgridCoordinate = x;
}
void Plant::setYgridCoordinate(int y)
{
	YgridCoordinate = y;
}
int Plant::getXgridCoordinate()
{
	return XgridCoordinate;
}
int Plant::getYgridCoordinate()
{
	return YgridCoordinate;
}
