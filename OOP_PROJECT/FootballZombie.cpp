#include "FootballZombie.h"

FootballZombie::FootballZombie()
{
	ZombieHealth = 180;
	zombieSpeed = 40 * ZOMBIE_SPEED_MULTIPLIER;
	damagePerSec = 0;
	is_Eating = false;
	Exists = false;
}
sf::Sprite& FootballZombie::getZombieSprite()
{
	return ZombieSprite;
}
int FootballZombie::getXgridCoordinate()
{
	return XgridCoordinate;
}
int FootballZombie::getYgridCoordinate()
{
	return YgridCoordinate;
}
void FootballZombie::setXgridCoordinate(float x)
{
	XgridCoordinate = x;
}
void FootballZombie::setYgridCoordinate(float y)
{
	YgridCoordinate = y;
}
float FootballZombie::getx_pos()
{
	return x_pos;
}
float FootballZombie::gety_pos()
{
	return y_pos;
}
bool FootballZombie::getExists()
{
	return Exists;
}
void FootballZombie::setx_pos(float x)
{
	x_pos = x;
}
void FootballZombie::sety_pos(float y)
{
	y_pos = y;
}
void FootballZombie::setExists(bool p_Exists)
{
	Exists = p_Exists;
}
void FootballZombie::damagePlant(Plant& plant)
{
	// get the health of plant and reduce it (inside for loop)
	// zombie_damage_clock.restart();
	is_Eating = true;

	if (zombie_damage_clock.getElapsedTime().asSeconds() > 1.5)
	{
		plant -= damagePerSec;
		if (plant.getPlantHealth() <= 0)
		{
			is_Eating = false;
		}
		zombie_damage_clock.restart();
	}
}
int FootballZombie::getZombieHealth()
{
	return ZombieHealth;
}
void FootballZombie::setAnimation()
{
	if (animationClock.getElapsedTime().asMilliseconds() > 350)
	{
		sf::IntRect textureRect = this->getZombieSprite().getTextureRect();

		if (textureRect.left >= 448)
		{
			textureRect.left = 0;
		}
		else
		{
			textureRect.left += 64;
		}
		this->getZombieSprite().setTextureRect(textureRect);
		animationClock.restart();
	}
}

void FootballZombie::moveZombie(float deltaTime)
{
	srand(time(0));
	if (!is_Eating)
	{
		x_pos -= (zombieSpeed * deltaTime);

		if (y_pos >= 40 && y_pos <= 520)  // Keeping the zombie within the grid
		{
			if (moveClock.getElapsedTime().asSeconds() > 2)
			{
				switch (rand() % 2)
				{
				case(0):  //  Move up
					if (y_pos >= 60 && y_pos <= 520)
					{
						y_pos -= 120;
					}
					break;
				case(1):  // Move down
					if (y_pos >= 40 && y_pos <= 400)
					{
						y_pos += 120;
					}
					break;
				}
				moveClock.restart();
			}
		}
	}

	ZombieSprite.setPosition(x_pos, y_pos);
}

void FootballZombie::operator-=(int damage)
{
	ZombieHealth -= damage;
	if (ZombieHealth <= 0)
	{
		Exists = false;
		x_pos = 1180;
		ZombieHealth = 180;
	}
}

void FootballZombie::setisEating(bool iseating)
{
	this->is_Eating = iseating;
}