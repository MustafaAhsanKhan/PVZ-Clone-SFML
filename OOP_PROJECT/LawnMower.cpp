#include "LawnMower.h"

bool LawnMower::ZombieCollided(Zombie& zombie)
{
	if (abs(zombie.getx_pos() - x_pos <= 20) && abs(zombie.gety_pos() - y_pos <= 15))
	{
		isActive = true;
		return 1;
	}
	else
	{
		return 0;
	}
	outofRes = false;
}
void LawnMower::moveLawnMower(float deltaTime)
{
	if (x_pos < 1450)
	{
		LawnMower::x_pos += lawnMowerSpeed * deltaTime;
		lawnmowerSprite.setPosition(x_pos, y_pos);
	}
	else if(x_pos > 1450)
	{
		isActive = false;
	}
}

void LawnMower::setx_pos(int x)
{
	x_pos = x;
}


void LawnMower::sety_pos(int y)
{
	y_pos = y;
}

float LawnMower::getx_pos()
{
	return x_pos;
}

bool LawnMower::getisActive()
{
	return isActive;
}

sf::Sprite& LawnMower::getLawnMowerSprite()
{
	return lawnmowerSprite;
}

bool LawnMower::OutofResolution()
{
	return outofRes;
}