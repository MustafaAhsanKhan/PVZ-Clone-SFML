#include "BulletPea.h"


BulletPea::BulletPea()
{
	this->x_pos = 0;
	this->y_pos = 0;
	this->damage = 10; // change according to game
	this->exists = false; // initially false 
	this->bulletSpeed = 1; // change to whatever speed
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

void BulletPea::move()
{
	
	if (exists)
	{
		//std::cout << "test";
		x_pos += bulletSpeed; // handling one bullet for now (shayad miss hi karate hain dusra)
		std::cout << x_pos;
	}
	if(x_pos > 740)
	{
		exists = false;
	}
		
}

void BulletPea::drawBullet(sf::RenderWindow& window)
{
	bulletSprite.setPosition(x_pos, y_pos);
	window.draw(bulletSprite);
}