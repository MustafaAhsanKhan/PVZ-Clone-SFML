#include "FumeShroom.h"

FumeShroom::FumeShroom()
{
	plantHealth = 100;
	MAX_BULLETS = 1;
	ShootingRate = 1;  // 1 second
	bullets = new Bullet[MAX_BULLETS];
	plantExists = false; // checks if plant exists
}

sf::Sprite& FumeShroom::getPlantSprite()
{
	return plantSprite;
}


void FumeShroom::Act()
{
	if (animationClock.getElapsedTime().asMilliseconds() > 400)
	{
		sf::IntRect textureRect = this->getPlantSprite().getTextureRect();
		if (textureRect.left >= 66)
		{
			textureRect.left = 0;
		}
		else
		{
			textureRect.left += 35;
		}
		this->getPlantSprite().setTextureRect(textureRect);
		animationClock.restart();
	}
}

// Update all bullets
void FumeShroom::shootBullet(float deltaTime)
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

Bullet& FumeShroom::getBullet(int index)
{
	return bullets[index];
}

int FumeShroom::getXgridCoordinate()
{
	return XgridCoordinate;
}

int FumeShroom::getYgridCoordinate()
{
	return YgridCoordinate;
}

void FumeShroom::setXgridCoordinate(int x)
{
	XgridCoordinate = x;
}

void FumeShroom::setYgridCoordinate(int y)
{
	YgridCoordinate = y;
}

int FumeShroom::getMaxBullets()
{
	return MAX_BULLETS;
}


void FumeShroom::setExists(bool ex)
{
	plantExists = ex;
}

bool FumeShroom::exists()
{
	return plantExists;
}



void FumeShroom::setSunClock()
{

}

sf::Clock& FumeShroom::getShootingRateClock()
{
	return ShootingRateClock;
}

Sun*& FumeShroom::getSun()
{
	return sun;
}

void FumeShroom::operator-=(int damage)
{
	plantHealth -= damage;
}

int FumeShroom::getPlantHealth()
{
	return plantHealth;
}