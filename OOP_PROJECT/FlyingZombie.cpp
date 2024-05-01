#include "FlyingZombie.h"

FlyingZombie::FlyingZombie()
{
	ZombieHealth = 100;
	XgridCoordinate = 0, YgridCoordinate = 0;
	zombieSpeed = 20000;
	damagePerSec = 0;
	is_Slowed = false;
}
sf::Sprite& FlyingZombie::getZombieSprite()
{
	return ZombieSprite;
}
int FlyingZombie::getXgridCoordinate()
{
	return XgridCoordinate;
}
int FlyingZombie::getYgridCoordinate()
{
	return YgridCoordinate;
}
void FlyingZombie::setXgridCoordinate(float x)
{
	XgridCoordinate = x;
}
void FlyingZombie::setYgridCoordinate(float y)
{
	YgridCoordinate = y;
}
float FlyingZombie::getx_pos()
{
	return x_pos;
}
float FlyingZombie::gety_pos()
{
	return y_pos;
}
void FlyingZombie::setx_pos(float x)
{
	x_pos = x;
}
void FlyingZombie::sety_pos(float y)
{
	y_pos = y;
}
void FlyingZombie::damagePlant(Plant&)
{
	// get the health of plant and reduce it (inside for loop)
}
int FlyingZombie::getZombieHealth()
{
	return ZombieHealth;
}
void FlyingZombie::setAnimation()
{
	if (animationClock.getElapsedTime().asMilliseconds() > 350)
	{
		sf::IntRect textureRect = this->getZombieSprite().getTextureRect();

		if (textureRect.left >= 297)  // animation moving right
		{
			textureRect.left = 0;
		}
		else
		{
			textureRect.left += 34;
		}
		this->getZombieSprite().setTextureRect(textureRect);
		animationClock.restart();
	}

}
void FlyingZombie::moveZombie(float deltaTime)
{
	x_pos -= (zombieSpeed * deltaTime);

	ZombieSprite.setPosition(x_pos, y_pos);
}