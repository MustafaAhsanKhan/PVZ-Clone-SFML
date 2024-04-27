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
void Shooter::moveBullets()
{

}
void Shooter::shootBullet()
{

}
void Shooter::setAnimation()
{

}
sf::Sprite& Shooter::getPlantSprite()
{
	return plantSprite;
}

void Shooter::setXgridcoordinate(int x)
{
	Xgridcoordinate = x;
}
void Shooter::setYgridcoordinate(int y)
{
	Ygridcoordinate = y;
}
int Shooter::getXgridcoordinate()
{
	return Xgridcoordinate;
}
int Shooter::getYgridcoordinate()
{
	return Ygridcoordinate;
}

