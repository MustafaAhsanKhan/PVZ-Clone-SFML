#include "FlyingZombie.h"

FlyingZombie::FlyingZombie()
{
	ZombieHealth = 100;
	zombieSpeed = 20;
	damagePerSec = 0;
	is_Eating = false;
	Exists = false;
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
bool FlyingZombie::getExists()
{
	return Exists;
}
void FlyingZombie::setx_pos(float x)
{
	x_pos = x;
}
void FlyingZombie::sety_pos(float y)
{
	y_pos = y;
}
void FlyingZombie::setExists(bool p_Exists)
{
	Exists = p_Exists;
}
void FlyingZombie::damagePlant(Plant& plant)
{
	// get the health of plant and reduce it (inside for loop)
	// zombie_damage_clock.restart();
	if (zombie_damage_clock.getElapsedTime().asSeconds() > 2)
	{
		zombie_damage_clock.restart();
	}
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

		if (textureRect.left >= 297)
		{
			textureRect.left = 0;
		}
		else
		{
			textureRect.left += 34.05;
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


void FlyingZombie::operator-=(int damage)
{
	ZombieHealth -= damage;
	if (ZombieHealth <= 0)
	{
		Exists = false;
		x_pos = 1180;
	}
}

void FlyingZombie::setisEating(bool iseating)
{
	this->is_Eating = iseating;
}