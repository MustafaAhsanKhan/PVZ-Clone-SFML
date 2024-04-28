#include "PeaShooter.h"

PeaShooter::PeaShooter()
{
	MAX_BULLETS = 2;
	ShootingRate = 2;  // 2 seconds
	bullets = new BulletPea[MAX_BULLETS];
}

sf::Sprite& PeaShooter::getPlantSprite()
{
	return plantSprite;
}


void PeaShooter::setAnimation()
{
	if (PS_animationClock.getElapsedTime().asMilliseconds() > 300)
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
		PS_animationClock.restart();
	}
}

// Update all bullets
void PeaShooter::shootBullet()
{
	for (int i = 0; i < this->getMaxBullets(); i++)
	{
		this->getBullet(i).setXPos(Xgridcoordinate * 100.66);
		this->getBullet(i).setYPos(Ygridcoordinate * 114);
	}
	
	if (ShootingRateClock.getElapsedTime().asSeconds() > ShootingRate)  // Making a new bullet after every 300 milliseconds
	{
		for (int i = 0; i < this->getMaxBullets(); ++i)
		{
			if (!bullets[i].getExists())
			{
				bullets[i].setExists(true);
				bullets[i].setXPos(Xgridcoordinate * 100.66);
				bullets[i].setYPos(Ygridcoordinate * 114);
				ShootingRateClock.restart();
				break;
			}
		}
	}

	for (int i = 0; i < this->getMaxBullets(); i++)
	{
		if (bullets[i].getExists())
		{
			bullets[i].move();
		}
	}
}


void PeaShooter::setMaxBullets(int bullets)
{
	
}
void PeaShooter::setShootingRate(float p_ShootingRate)
{
	cout << "temp";
}
BulletPea& PeaShooter::getBullet(int index)
{
	return bullets[index];
}

int PeaShooter::getXgridcoordinate()
{
	return Xgridcoordinate;
}

int PeaShooter::getYgridcoordinate()
{
	return Ygridcoordinate;
}

void PeaShooter::setXgridcoordinate(int x)
{
	Xgridcoordinate = x;
}

void PeaShooter::setYgridcoordinate(int y)
{
	Ygridcoordinate = y;
}

int PeaShooter::getMaxBullets()
{
	return MAX_BULLETS;
}

PeaShooter::~PeaShooter()
{
	delete[] bullets;
}

