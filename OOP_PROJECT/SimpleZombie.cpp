#include "SimpleZombie.h"

SimpleZombie::SimpleZombie()
{
	ZombieHealth = 90;
	zombieSpeed = 20 * ZOMBIE_SPEED_MULTIPLIER;
	damagePerSec = 10;
	is_Eating = false;
	Exists = false;
}
sf::Sprite& SimpleZombie::getZombieSprite()
{
	return ZombieSprite;
}
int SimpleZombie::getXgridCoordinate()
{
	return XgridCoordinate;
}
int SimpleZombie::getYgridCoordinate()
{
	return YgridCoordinate;
}
void SimpleZombie::setXgridCoordinate(float x)
{
	XgridCoordinate = x;
}
void SimpleZombie::setYgridCoordinate(float y)
{
	YgridCoordinate = y;
}
void SimpleZombie::damagePlant(Plant& plant)
{
	// get the health of plant and reduce it (inside for loop)
	// zombie_damage_clock.restart();
	is_Eating = true;
	if (zombie_damage_clock.getElapsedTime().asSeconds() > 2)
	{
		plant -= damagePerSec;
		if (plant.getPlantHealth() <= 0)
		{
			is_Eating = false;
		}
		zombie_damage_clock.restart();
	}
}

int SimpleZombie::getZombieHealth()
{
    return ZombieHealth;
}
void SimpleZombie::setAnimation()
{
	if (animationClock.getElapsedTime().asMilliseconds() > 350)
	{
		sf::IntRect textureRect = this->getZombieSprite().getTextureRect();
		
		if (textureRect.left >= 300)
		{
			textureRect.left = 5;
		}
		else
		{
			textureRect.left += 50;
		}
		this->getZombieSprite().setTextureRect(textureRect);
		animationClock.restart();
	}
}

float SimpleZombie::getx_pos()
{
	return x_pos;
}
float SimpleZombie::gety_pos()
{
	return y_pos;
}
bool SimpleZombie::getExists()
{
	return Exists;
}
void SimpleZombie::setx_pos(float x)
{
	x_pos = x;
}
void SimpleZombie::sety_pos(float y)
{
	y_pos = y;
}
void SimpleZombie::setExists(bool p_Exists)
{
	Exists = p_Exists;
}
void SimpleZombie::moveZombie(float deltaTime)
{
	if (!is_Eating)
	{
		x_pos -= (zombieSpeed * deltaTime);
	}
		
	
	ZombieSprite.setPosition(x_pos, y_pos);
}

void SimpleZombie::operator-=(int damage)
{
    ZombieHealth = ZombieHealth - damage;
	if(ZombieHealth <= 0)
	{
		Exists = false;
		x_pos = 1180;
		ZombieHealth = 90;
	}
}

void SimpleZombie::setisEating(bool iseating)
{
	this->is_Eating = iseating;
}