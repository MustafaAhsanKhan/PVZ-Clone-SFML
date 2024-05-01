#include "SimpleZombie.h"

SimpleZombie::SimpleZombie()
{
	ZombieHealth = 100; // change later if needed
	XgridCoordinate = 0, YgridCoordinate = 0;
	zombieSpeed = 10000; // change later if needed
	damagePerSec = 10; // change later if needed
	is_Slowed = false;
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
}

int SimpleZombie::getZombieHealth()
{
    return ZombieHealth;
}
void SimpleZombie::setAnimation()
{
	if (animationClock.getElapsedTime().asMilliseconds() > 300)
	{
		sf::IntRect textureRect = this->getZombieSprite().getTextureRect();
		
		if (textureRect.left >= 300)  // animation moving right
		{
			textureRect.left = 0;
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
void SimpleZombie::setx_pos(float x)
{
	x_pos = x;
}
void SimpleZombie::sety_pos(float y)
{
	y_pos = y;
}

void SimpleZombie::moveZombie(float deltaTime)
{
	x_pos -= (zombieSpeed * deltaTime);
	
	ZombieSprite.setPosition(x_pos, y_pos);
	//XgridCoordinate = (x_pos / ;
}