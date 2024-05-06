#include "SnowPea.h"

SnowPea::SnowPea()
{
	MAX_BULLETS = 2;
	ShootingRate = 1;  // 1 second
	bullets = new BulletPea[MAX_BULLETS];
	Suncost = 100; // initializing the cost of Peashooter
	plantExists = false; // checks if plant exists
}

sf::Sprite& SnowPea::getPlantSprite()
{
	return plantSprite;
}


void SnowPea::setAnimation()
{
	cout << "SETTING ANIMATION FOR SNOW PEA...";
	if (animationClock.getElapsedTime().asMilliseconds() > 300)
	{
		sf::IntRect textureRect = this->getPlantSprite().getTextureRect();
		if (textureRect.left >= 188.75)
		{
			textureRect.left = 0;
		}
		else
		{
			textureRect.left += 27.25;
		}
		this->getPlantSprite().setTextureRect(textureRect);
		animationClock.restart();
	}
}

// Update all bullets
void SnowPea::shootBullet(float deltaTime)
{

	if (ShootingRateClock.getElapsedTime().asSeconds() > ShootingRate)  // Making a new bullet after every 300 milliseconds
	{
		for (int i = 0; i < this->getMaxBullets(); ++i)
		{
			if (!bullets[i].getExists() && plantExists) // removed this condition since the rate will be constant and wont depend on if the bullet exists or not
			{
				bullets[i].setExists(true);
				bullets[i].setXPos(XgridCoordinate * 100.66 + 380); // correctly alligned
				bullets[i].setYPos(YgridCoordinate * 114 + 110); // correctly alligned
				ShootingRateClock.restart();
				break;
			}
		}
	}

	for (int i = 0; i < this->getMaxBullets(); i++)
	{
		if (bullets[i].getExists())
		{
			bullets[i].move(deltaTime);
		}
	}
}

BulletPea& SnowPea::getBullet(int index)
{
	return bullets[index];
}

int SnowPea::getXgridCoordinate()
{
	return XgridCoordinate;
}

int SnowPea::getYgridCoordinate()
{
	return YgridCoordinate;
}

void SnowPea::setXgridCoordinate(int x)
{
	XgridCoordinate = x;
}

void SnowPea::setYgridCoordinate(int y)
{
	YgridCoordinate = y;
}

int SnowPea::getMaxBullets()
{
	return MAX_BULLETS;
}

void SnowPea::setExists(bool ex)
{
	plantExists = ex;
}

bool SnowPea::exists()
{
	return plantExists;
}

