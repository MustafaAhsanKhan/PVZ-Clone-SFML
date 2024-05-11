#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstdlib>

class Sun
{
private:
	sf::Sprite sunSprite;
	float x_pos, y_pos;
	float sunSpeed;
	bool collected;
	bool sunExists;
public:
	Sun();
	void move();
	void setCollected(bool ex);
	bool Collected();
	bool exists();
	void setExists(bool p_SunExists);
	float getXpos();
	float getYpos();
	void resetPosition();
	sf::Sprite& getSunSprite();
};

