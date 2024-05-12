#include "BackupDancerZombie.h"

BackupDancerZombie::BackupDancerZombie()
{
	ZombieHealth = 90;
	zombieSpeed = 20;
	damagePerSec = 0;
	is_Slowed = false;
	movingUp = true;
	Exists = false;
}
sf::Sprite& BackupDancerZombie::getZombieSprite()
{
	return ZombieSprite;
}
int BackupDancerZombie::getXgridCoordinate()
{
	return XgridCoordinate;
}
int BackupDancerZombie::getYgridCoordinate()
{
	return YgridCoordinate;
}
void BackupDancerZombie::setXgridCoordinate(float x)
{
	XgridCoordinate = x;
}
void BackupDancerZombie::setYgridCoordinate(float y)
{
	YgridCoordinate = y;
}
float BackupDancerZombie::getx_pos()
{
	return x_pos;
}
float BackupDancerZombie::gety_pos()
{
	return y_pos;
}
bool BackupDancerZombie::getExists()
{
	return Exists;
}
void BackupDancerZombie::setx_pos(float x)
{
	x_pos = x;
}
void BackupDancerZombie::sety_pos(float y)
{
	y_pos = y;
}
void BackupDancerZombie::setExists(bool p_Exists)
{
	Exists = p_Exists;
}
void BackupDancerZombie::damagePlant(Plant& plant)
{
	plant -= damagePerSec;
}
int BackupDancerZombie::getZombieHealth()
{
	return ZombieHealth;
}
void BackupDancerZombie::setAnimation()
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
void BackupDancerZombie::moveZombie(float deltaTime)
{
	x_pos -= (zombieSpeed * deltaTime);

	if (y_pos >= -200 && y_pos <= 540 && movingUp == true)
	{
		// move the zombie up
		if (y_pos > 40)
		{
			y_pos -= zombieSpeed * deltaTime;
		}
		else
		{
			movingUp = false;
		}
	}
	else if (y_pos >= -200 && y_pos <= 540 && movingUp == false)
	{
		// move the zombie down
		if (y_pos < 520)
		{
			y_pos += zombieSpeed * deltaTime;
		}
		else
		{
			movingUp = true;
		}
	}


	ZombieSprite.setPosition(x_pos, y_pos);
}

void BackupDancerZombie::operator-=(int damage)
{
    ZombieHealth = ZombieHealth - damage;
	if (ZombieHealth <= 0)
	{
		Exists = false;
		x_pos = 1180;
		ZombieHealth = 90;
	}
}