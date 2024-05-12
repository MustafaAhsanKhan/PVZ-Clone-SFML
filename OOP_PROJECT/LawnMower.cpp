#include "LawnMower.h"

bool LawnMower::ZombieCollided(Zombie& zombie)
{
	return lawnmowerSprite.getGlobalBounds().intersects(zombie.getZombieSprite().getGlobalBounds());
}
bool LawnMower::moveLawnMower(Zombie& zombie, float deltaTime)
{
	if (ZombieCollided(zombie))
	{
		if (x_pos < 1350)
		{
			cout << "Collided with zombie !! " << endl;
			LawnMower::x_pos += lawnMowerSpeed * deltaTime;
			lawnmowerSprite.setPosition(x_pos, y_pos);
			cout << x_pos << endl;
			return false;
		}

		else
			return true;
	}
	
		
}

void LawnMower::setX_pos(int x)
{
	x_pos = x;
}


void LawnMower::setY_pos(int y)
{
	y_pos = y;
}

float LawnMower::getX_pos()
{
	return x_pos;
}

sf::Sprite& LawnMower::getLawnMowerSprite()
{
	return lawnmowerSprite;
}