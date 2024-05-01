#include "Zombie.h"

Zombie::Zombie()
{
	ZombieHealth = 0;
	XgridCoordinate = 0, YgridCoordinate = 0;
	zombieSpeed = 0;
	damagePerSec = 0;
	is_Slowed = false;
}
sf::Sprite& Zombie::getZombieSprite()
{
	return ZombieSprite;
}
int Zombie::getXgridCoordinate()
{
	return XgridCoordinate;
}
int Zombie::getYgridCoordinate()
{
	return YgridCoordinate;
}
void Zombie::setXgridCoordinate(float x)
{
	XgridCoordinate = x;
}
void Zombie::setYgridCoordinate(float y)
{
	YgridCoordinate = y;
}
float Zombie::getx_pos()
{
	return x_pos;
}
float Zombie::gety_pos()
{
	return y_pos;
}
void Zombie::setx_pos(float x)
{
	x_pos = x;
}
void Zombie::sety_pos(float y)
{
	y_pos = y;
}
void Zombie::damagePlant(Plant& plant)
{
	
}

int Zombie::getZombieHealth()
{
	return ZombieHealth;
}
void Zombie::setAnimation()
{
	
}

void Zombie::moveZombie(float deltaTime)
{
	
}