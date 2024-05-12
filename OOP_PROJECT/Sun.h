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
	bool sunExists;
public:
	Sun();
	void move(float deltaTime);
	bool getExists();
	void setExists(bool p_SunExists);
	void setXpos(int x);
	void setYpos(int y);
	float getXpos();
	float getYpos();
	void resetPosition();
	sf::Sprite& getSunSprite();
};

