#include "PeaShooter.h"

PeaShooter::PeaShooter()
{
	MAX_BULLETS = 2;
	ShootingRate = 300;  // 300 milliseconds
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

/*
void PeaShooter::shootBullet()
{
	// Find an available bullet slot and shoot
	for (int i = 0; i < MAX_BULLETS; ++i)
	{
		if (!bullets[i].getExists())
		{
			// bullets[i].shoot(Xgridcoordinate, Ygridcoordinate);
			break;
		}
	}
}*/

// Update all bullets
void PeaShooter::shootBullet()
{
	
	this->bullets[0].setExists(true);
	bullets[0].move();
	if (bullets[0].getXPos() > 700)
	{
		bullets[0].setExists(false);
		bullets[1].setExists(true);
		bullets[1].move();
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

