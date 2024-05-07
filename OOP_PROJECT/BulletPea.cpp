#include "BulletPea.h"


BulletPea::BulletPea()
{
	this->x_pos = 0;
	this->y_pos = 0;
	this->damage = 10; // change according to game
	this->exists = false; // initially false  
	/*
	this variable is only to check if the bullet should draw or not. 
	Its not going to depend on the rate at which the plant shoots. 
	Hence when the bullet becomes false we just need to set its position back to the plant's
	*/
	this->bulletSpeed = 2000; // change to whatever speed
}
// Getters
float BulletPea::getBulletSpeed()
{
	return bulletSpeed;
}
int BulletPea::getDamage()
{
	return damage;
}
float BulletPea::getXPos()
{
	return x_pos;
}
float BulletPea::getYPos()
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

void BulletPea::move(float deltaTime)
{
	if (exists)
	{
		x_pos += bulletSpeed * deltaTime;
	}	
	if (x_pos > 1350)
	{
		exists = false;
	}
}

void BulletPea::drawBullet(sf::RenderWindow& window)
{
	bulletSprite.setPosition(x_pos, y_pos);
	if (exists)
	{
		window.draw(bulletSprite); // only draws when the bullet exists
	}
	
}