#include "PeaShooter.h"

PeaShooter::PeaShooter()
{
	plantHealth = 100;
	MAX_BULLETS = 1;
	ShootingRate = 2;  // 1 second
	bullets = new Bullet[MAX_BULLETS];
	plantExists = false; // checks if plant exists
}

sf::Sprite& PeaShooter::getPlantSprite()
{
	return plantSprite;
}


void PeaShooter::Act()
{
	// cout << "SETTING ANIMATION FOR PEASHOOTER...";
	if (animationClock.getElapsedTime().asMilliseconds() > 300)
	{
		sf::IntRect textureRect = plantSprite.getTextureRect();
		if (textureRect.left >= 188.75)
		{
			textureRect.left = 0;
		}
		else
		{
			textureRect.left += 27.25;
		}
		plantSprite.setTextureRect(textureRect);
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

Bullet& PeaShooter::getBullet(int index)
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


void PeaShooter::setExists(bool ex)
{
	plantExists = ex;
}

bool PeaShooter::exists()
{
	return plantExists;
}

void PeaShooter::setSunClock()
{

}
Sun*& PeaShooter::getSun()
{
	return sun;
}

sf::Clock& PeaShooter::getShootingRateClock()
{
	return ShootingRateClock;
}

PeaShooter::~PeaShooter()
{
	delete[] bullets;
}

void PeaShooter::operator-=(int damage)
{
	plantHealth -= damage;
	cout << "Damaged! Health: " << plantHealth << endl;
}


int PeaShooter::getPlantHealth()
{
	return plantHealth;
}