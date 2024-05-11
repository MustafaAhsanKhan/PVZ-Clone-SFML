#include "Sun.h"

Sun::Sun()
{
	//int i = (rand() % 100);
	//x_pos = (rand() % (6 * 12)) + 200; // random x position
	x_pos = 400;
	y_pos = -100; // out of frame currently
	sunSpeed = 0.2;
	//collected = false;
	sunExists = false;
}

void Sun::move()
{
	if (!(y_pos >= 675))
	{
		y_pos += sunSpeed;
	}
	this->getSunSprite().setPosition(x_pos, y_pos);
}

sf::Sprite& Sun::getSunSprite()
{
	return sunSprite;
}

bool Sun::Collected()
{
	return collected;
}

void Sun::setCollected(bool co)
{
	collected = co;
}
void Sun::setExists(bool ex)
{
	sunExists = ex;
}

bool Sun::exists()
{
	return sunExists;
}

float Sun::getXpos()
{
	return x_pos;
}

float Sun::getYpos()
{
	return y_pos;
}

void Sun::resetPosition()
{
	//int i = (rand() % 100);
	//x_pos = (rand() % (6 * 12)) + 200; // random x position
	x_pos = 400;
	y_pos = -100; // out of frame currently
}