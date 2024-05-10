#include "WallNut.h"

WallNut::WallNut()
{
	Suncost = 50; // cost 
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
	srand(time(0));
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	int verticalDirection = (std::rand() % 3) - 1; // up or down direction
	sf::Vector2f currentPosition = getPlantSprite().getPosition();
	float speed = 0.75f; // Adjust the speed of movement as needed
	float Yspeed = speed / 3 * verticalDirection;
	bool initialRollingPhase = animationClock.getElapsedTime().asMilliseconds() < 3000;

	sf::Vector2f newPosition(currentPosition.x + speed, currentPosition.y + Yspeed);
	this->getPlantSprite().setPosition(newPosition);

	if (animationClock.getElapsedTime().asMilliseconds() > 200)
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