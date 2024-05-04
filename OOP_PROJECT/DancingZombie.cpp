#include "DancingZombie.h"

DancingZombie::DancingZombie()
{
	ZombieHealth = 100;
	XgridCoordinate = 0, YgridCoordinate = 0;
	zombieSpeed = 30000;
	damagePerSec = 0;
	is_Slowed = false;

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
void DancingZombie::setx_pos(float x)
{
	x_pos = x;
}
void DancingZombie::sety_pos(float y)
{
	y_pos = y;
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

	ZombieSprite.setPosition(x_pos, y_pos);
}