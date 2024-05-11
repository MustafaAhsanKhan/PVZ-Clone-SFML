#include "Sun.h"

Sun::Sun()
{
	int i = (rand() % 100);
	x_pos = (rand() % (i * 12)) + 300; // random x position
	x_pos = 400;
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
	int i = (rand() % 100);
	x_pos = (rand() % (i * 12)) + 300; // random x position
	x_pos = 400;
	y_pos = -100; // out of frame currently
}