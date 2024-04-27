#include "BulletPea.h"

// Getters
int BulletPea::getBulletSpeed()
{
	return bulletSpeed;
}
int BulletPea::getDamage()
{
	return damage;
}
int BulletPea::getXPos()
{
	return x_pos;
}
int BulletPea::getYPos()
{
	return y_pos;
}
bool BulletPea::getExists()
{
	return exists;
}

sf::Sprite& BulletPea::getBulletSprite()
{
	return bulletSprite;
}

// Setters
void BulletPea::setBulletSpeed(int speed)
{
	bulletSpeed = speed;

}
void BulletPea::setDamage(int damage)
{
	this->damage = damage;
}
void BulletPea::setXPos(int x)
{
	x_pos = x;
}
void BulletPea::setYPos(int y)
{
	y_pos = y;
}
void BulletPea::setExists(bool exists)
{
	this->exists = exists;
}

void BulletPea::shoot(int XgridCoordinate, int YgridCoordinate)
{
	x_pos = XgridCoordinate;
	y_pos = YgridCoordinate;
	exists = true;
}

void BulletPea::move()
{
	x_pos += bulletSpeed;
	if (x_pos > 800)
	{
		exists = false;
	}
}

void BulletPea::drawBullet(sf::RenderWindow& window)
{
	bulletSprite.setPosition(x_pos, y_pos);
	window.draw(bulletSprite);
}