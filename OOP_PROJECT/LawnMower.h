#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Zombie.h"
using namespace std;

class LawnMower
{
private:
	sf::Sprite lawnmowerSprite;
	float x_pos, y_pos;
	float lawnMowerSpeed;
public:
	LawnMower() : x_pos(0), lawnMowerSpeed(600) {}
	bool ZombieCollided(Zombie& zombie);
	bool moveLawnMower(Zombie& zombie, float deltaTime);
	void setX_pos(int x);
	float getX_pos();
	void setY_pos(int y);
	sf::Sprite& getLawnMowerSprite();
};

