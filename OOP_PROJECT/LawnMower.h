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
	bool isActive;
public:
	LawnMower() : x_pos(0), lawnMowerSpeed(600), isActive(0) {}
	bool ZombieCollided(Zombie& zombie);
	void moveLawnMower(float deltaTime);
	void setx_pos(int x);
	float getx_pos();
	void sety_pos(int y);
	bool getisActive();
	sf::Sprite& getLawnMowerSprite();
};

