#include "DolphinRiderZombie.h"

DolphinRiderZombie::DolphinRiderZombie()
{
	ZombieHealth = 100;
	zombieSpeed = 20 * ZOMBIE_SPEED_MULTIPLIER;
	damagePerSec = 0;
	is_Slowed = false;
	Exists = false;
}
sf::Sprite& DolphinRiderZombie::getZombieSprite()
{
	return ZombieSprite;
}
int DolphinRiderZombie::getXgridCoordinate()
{
	return XgridCoordinate;
}
int DolphinRiderZombie::getYgridCoordinate()
{
	return YgridCoordinate;
}
void DolphinRiderZombie::setXgridCoordinate(float x)
{
	XgridCoordinate = x;
}
void DolphinRiderZombie::setYgridCoordinate(float y)
{
	YgridCoordinate = y;
}
float DolphinRiderZombie::getx_pos()
{
	return x_pos;
}
float DolphinRiderZombie::gety_pos()
{
	return y_pos;
}
void DolphinRiderZombie::setx_pos(float x)
{
	x_pos = x;
}
void DolphinRiderZombie::sety_pos(float y)
{
	y_pos = y;
}
void DolphinRiderZombie::damagePlant(Plant&)
{

}
int DolphinRiderZombie::getZombieHealth()
{
	return ZombieHealth;
}
void DolphinRiderZombie::setAnimation()
{
	if (animationClock.getElapsedTime().asMilliseconds() > 350)
	{
		sf::IntRect textureRect = this->getZombieSprite().getTextureRect();

		if (textureRect.left >= 280)
		{
			textureRect.left = 0;
		}
		else
		{
			textureRect.left += 56;
		}
		this->getZombieSprite().setTextureRect(textureRect);
		animationClock.restart();
	}
}
void DolphinRiderZombie::moveZombie(float deltaTime)
{
	x_pos -= (zombieSpeed * deltaTime);

	ZombieSprite.setPosition(x_pos, y_pos);
}