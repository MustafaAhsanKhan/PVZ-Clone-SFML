#include "PeaShooter.h"

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


void PeaShooter::shootBullet()
{
	// Find an available bullet slot and shoot
	for (int i = 0; i < MAX_BULLETS; ++i)
	{
		if (!bullets[i].getExists())
		{
			bullets[i].shoot(Xgridcoordinate, Ygridcoordinate);
			break;
		}
	}
}

// Update all bullets
void PeaShooter::moveBullets()
{
	for (int i = 0; i < MAX_BULLETS; ++i)
	{
		if (bullets[i].getExists())
		{
			bullets[i].move();
		}
	}
}
