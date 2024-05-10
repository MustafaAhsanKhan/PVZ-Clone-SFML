#include "Cherrybomb.h"

Cherrybomb::Cherrybomb()
{
	Suncost = 50; // cost 
	plantExists = false;
	XgridCoordinate = 0;
	YgridCoordinate = 0;
}

sf::Sprite& Cherrybomb::getPlantSprite()
{
	return plantSprite;
}

void Cherrybomb::Act() 
{

	bool exploding = false;
	int limit = 213;
	if (animationClock.getElapsedTime().asMilliseconds() > 500)
	{
		sf::IntRect textureRect = this->getPlantSprite().getTextureRect();
		if (textureRect.left >= limit)
		{
			textureRect.width = 47;
			textureRect.left = 68;
		}
		else
		{
			//if (textureRect.left == 0)
			//{
			//	//textureRect.width = 47;
			//	textureRect.left += 33;
			//}
			//else if (textureRect.left == 33)
			//{
			//	//textureRect.width = 47;
			//	textureRect.left += 35;
			//}
			if (textureRect.left == 68 || textureRect.left == 115)
			{
				textureRect.width = 53;
				textureRect.left += 47;
			}
			else if (textureRect.left == 162)
			{
				textureRect.width = 53;
				textureRect.left += 53;
			}
			else
			{
				// textureRect.width = 33;
			}
				

		}
		//if (textureRect.left >= limit && !exploding)
		//{
		//	exploding = true;
		//	textureRect.top += 39;
		//	textureRect.left = 0;
		//	// plantExists = false; // will explode 
		//}
		

		this->getPlantSprite().setTextureRect(textureRect);
		animationClock.restart();
	}
}

void Cherrybomb::setXgridCoordinate(int x)
{
	XgridCoordinate = x;
}
void Cherrybomb::setYgridCoordinate(int y)
{
	YgridCoordinate = y;
}
int Cherrybomb::getXgridCoordinate()
{
	return XgridCoordinate;
}
int Cherrybomb::getYgridCoordinate()
{
	return YgridCoordinate;
}

void Cherrybomb::setExists(bool ex)
{
	plantExists = ex;
}

bool Cherrybomb::exists()
{
	return plantExists;
}