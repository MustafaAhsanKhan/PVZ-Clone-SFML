#include "PeaShooter.h"

PeaShooter::PeaShooter()
{
	MAX_BULLETS = 2;
	ShootingRate = 1;  // 1 second
	bullets = new BulletPea[MAX_BULLETS];
	Suncost = 100; // initializing the cost of Peashooter
	plantExists = false; // checks if plant exists
}

sf::Sprite& PeaShooter::getPlantSprite()
{
	return plantSprite;
}


void PeaShooter::setAnimation()
{
	// cout << "SETTING ANIMATION FOR PEASHOOTER...";
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
void PeaShooter::shootBullet(float deltaTime)
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


void PeaShooter::setMaxBullets(int bullets)
{
	
}
void PeaShooter::setShootingRate(float p_ShootingRate)
{
	
}
BulletPea& PeaShooter::getBullet(int index)
{
	return bullets[index];
}

int PeaShooter::getXgridCoordinate()
{
	return XgridCoordinate;
}

int PeaShooter::getYgridCoordinate()
{
	return YgridCoordinate;
}

void PeaShooter::setXgridCoordinate(int x)
{
	XgridCoordinate = x;
}

void PeaShooter::setYgridCoordinate(int y)
{
	YgridCoordinate = y;
}

int PeaShooter::getMaxBullets()
{
	return MAX_BULLETS;
}

PeaShooter::~PeaShooter()
{
	delete[] bullets;
}

void PeaShooter::setExists(bool ex)
{
	plantExists = ex;
}

bool PeaShooter::exists()
{
	return plantExists;
}

