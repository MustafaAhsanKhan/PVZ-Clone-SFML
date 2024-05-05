#include "FootballZombie.h"

FootballZombie::FootballZombie()
{
	ZombieHealth = 100;
	XgridCoordinate = 0, YgridCoordinate = 0;
	zombieSpeed = 30000;
	damagePerSec = 0;
	is_Slowed = false;
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
void FootballZombie::setx_pos(float x)
{
	x_pos = x;
}
void FootballZombie::sety_pos(float y)
{
	y_pos = y;
}
void FootballZombie::damagePlant(Plant&)
{

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
	x_pos -= (zombieSpeed * deltaTime);

	ZombieSprite.setPosition(x_pos, y_pos);
}