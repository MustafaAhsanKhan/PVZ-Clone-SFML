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
}
void LawnMower::moveLawnMower(float deltaTime)
{
	if (x_pos < 1350)
	{
		cout << "Collided with zombie !! " << endl;
		LawnMower::x_pos += lawnMowerSpeed * deltaTime;
		lawnmowerSprite.setPosition(x_pos, y_pos);
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