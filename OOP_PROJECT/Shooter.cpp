#include "Shooter.h"

void Shooter::setMaxBullets(int bullets)
{

}
void Shooter::setShootingRate(float p_ShootingRate)
{

}
BulletPea& Shooter::getBullet(int index)
{
	return bullets[index];
}

void Shooter::shootBullet(float deltaTime)
{

}
void Shooter::setAnimation()
{

}
sf::Sprite& Shooter::getPlantSprite()
{
	return plantSprite;
}

void Shooter::setXgridCoordinate(int x)
{
	XgridCoordinate = x;
}
void Shooter::setYgridCoordinate(int y)
{
	YgridCoordinate = y;
}
int Shooter::getXgridCoordinate()
{
	return XgridCoordinate;
}
int Shooter::getYgridCoordinate()
{
	return YgridCoordinate;
}

int Shooter::getMaxBullets()
{
	return MAX_BULLETS;
}