#include "DancingZombie.h"

DancingZombie::DancingZombie()
{
	ZombieHealth = 120;
	zombieSpeed = 20 * ZOMBIE_SPEED_MULTIPLIER;
	damagePerSec = 0;
	is_Slowed = false;
	movingUp = true;
	Exists = false;
	numBackupZombiesSpawned = 0;

}
sf::Sprite& DancingZombie::getZombieSprite()
{
	return ZombieSprite;
}
int DancingZombie::getXgridCoordinate()
{
	return XgridCoordinate;
}
int DancingZombie::getYgridCoordinate()
{
	return YgridCoordinate;
}
void DancingZombie::setXgridCoordinate(float x)
{
	XgridCoordinate = x;
}
void DancingZombie::setYgridCoordinate(float y)
{
	YgridCoordinate = y;
}
float DancingZombie::getx_pos()
{
	return x_pos;
}
float DancingZombie::gety_pos()
{
	return y_pos;
}
bool DancingZombie::getExists()
{
	return Exists;
}
void DancingZombie::setx_pos(float x)
{
	x_pos = x;
}
void DancingZombie::sety_pos(float y)
{
	y_pos = y;
}
void DancingZombie::setExists(bool p_Exists)
{
	Exists = p_Exists;
}
void DancingZombie::damagePlant(Plant&)
{

}
int DancingZombie::getZombieHealth()
{
	return ZombieHealth;
}
void DancingZombie::setAnimation()
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
void DancingZombie::moveZombie(float deltaTime)
{
	x_pos -= (zombieSpeed * deltaTime);

	if (y_pos >= 20 && y_pos <= 540 && movingUp == true)
	{
		// move the zombie up
		if(y_pos > 40)
		{
			y_pos -= zombieSpeed * deltaTime;
		}
		else
		{
			movingUp = false;
		}
	}
	else if (y_pos >= 20 && y_pos <= 540 && movingUp == false)
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

void DancingZombie::operator-=(int damage)
{
	ZombieHealth -= damage;
	if (ZombieHealth <= 0)
	{
		Exists = false;
		x_pos = 1180;
		ZombieHealth = 120;
		numBackupZombiesSpawned = 0;
	}
}