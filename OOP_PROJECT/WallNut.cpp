#include "WallNut.h"

WallNut::WallNut()
{
	plantHealth = 300;
	plantExists = false;
	XgridCoordinate = 0;
	YgridCoordinate = 0;
}

sf::Sprite& WallNut::getPlantSprite()
{
	return plantSprite;
}

void WallNut::Act() 
{
	sf::Vector2f currentPosition = getPlantSprite().getPosition();
	float speed = 0.25f;
	int Xlimit = XgridCoordinate * 100.66 + 315;
	bool limitCrossed = currentPosition.x > Xlimit;
	int startingPosition = currentPosition.x;


	sf::Vector2f newPosition;

	if (animationClock.getElapsedTime().asMilliseconds() > 100)
	{

		sf::IntRect textureRect = this->getPlantSprite().getTextureRect();
		if (textureRect.left >= 204.875 - 29.125)
		{
			textureRect.left = 0;
		}
		else
		{
			textureRect.left += 29.125;
		}
		this->getPlantSprite().setTextureRect(textureRect);
		animationClock.restart();
	}
	

	if (!limitCrossed)
	{
		newPosition = sf::Vector2f((startingPosition - 300) + speed, currentPosition.y);
		
	}
	else
	{
		newPosition = sf::Vector2f((startingPosition) + speed, currentPosition.y);
	}

	this->getPlantSprite().setPosition(newPosition);
	
}

void WallNut::setXgridCoordinate(int x)
{
	XgridCoordinate = x;
}
void WallNut::setYgridCoordinate(int y)
{
	YgridCoordinate = y;
}
int WallNut::getXgridCoordinate()
{
	return XgridCoordinate;
}
int WallNut::getYgridCoordinate()
{
	return YgridCoordinate;
}

void WallNut::setExists(bool ex)
{
	plantExists = ex;
}

bool WallNut::exists()
{
	return plantExists;
}

void WallNut::operator-=(int damage)
{
	plantHealth -= damage;
}

void WallNut::setSunClock()
{

}
Sun*& WallNut::getSun()
{
	return sun;
}

int WallNut::getPlantHealth()
{
	return plantHealth;
}