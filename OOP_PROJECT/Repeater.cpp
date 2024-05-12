#include "Repeater.h"

Repeater::Repeater()
{
	MAX_BULLETS = 2;
	ShootingRate = 0.2;  // 1 second
	bullets = new Bullet[MAX_BULLETS];
	plantExists = false; // checks if plant exists
}

sf::Sprite& Repeater::getPlantSprite()
{
	return plantSprite;
}


void Repeater::Act()
{
	// cout << "SETTING ANIMATION FOR PEASHOOTER...";
	if (animationClock.getElapsedTime().asMilliseconds() > 350)
	{
		sf::IntRect textureRect = this->getPlantSprite().getTextureRect();
		if (textureRect.left >= 140)
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
void Repeater::shootBullet(float deltaTime)
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

Bullet& Repeater::getBullet(int index)
{
	return bullets[index];
}

int Repeater::getXgridCoordinate()
{
	return XgridCoordinate;
}

int Repeater::getYgridCoordinate()
{
	return YgridCoordinate;
}

void Repeater::setXgridCoordinate(int x)
{
	XgridCoordinate = x;
}

void Repeater::setYgridCoordinate(int y)
{
	YgridCoordinate = y;
}

int Repeater::getMaxBullets()
{
	return MAX_BULLETS;
}

void Repeater::setExists(bool ex)
{
	plantExists = ex;
}

bool Repeater::exists()
{
	return plantExists;
}

Repeater::~Repeater()
{
	delete[] bullets;
}

void Repeater::setSunClock()
{

}
Sun*& Repeater::getSun()
{
	return sun;
}
