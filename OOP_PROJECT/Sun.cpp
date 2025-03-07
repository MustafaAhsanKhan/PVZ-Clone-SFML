#include "Sun.h"

Sun::Sun()
{
	int i = (rand() % 100) + 1;
	x_pos = (rand() % (i * 8)) + 300; // random x position
	y_pos = -100; // out of frame currently
	sunSpeed = 70;
	sunExists = false;
}

void Sun::move(float deltaTime)
{
	if (!(y_pos >= 660))
	{
		y_pos += sunSpeed * deltaTime;
	}
	this->getSunSprite().setPosition(x_pos, y_pos);
}

sf::Sprite& Sun::getSunSprite()
{
	return sunSprite;
}

void Sun::setExists(bool ex)
{
	sunExists = ex;
}

bool Sun::getExists()
{
	return sunExists;
}

void Sun::setXpos(int x)
{
	this->x_pos = x;
}

void Sun::setYpos(int y)
{
	this->y_pos = y;
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
	int i = (rand() % 100) + 1;
	x_pos = (rand() % (i * 12)) + 300; // random x position
	y_pos = -100; // out of frame currently
}