#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Zombie.h"
using namespace std;

class LawnMower
{
private:
	sf::Sprite lawnmowerSprite;
	float x_pos;
	float lawnMowerSpeed;
public:
	LawnMower() : x_pos(0), lawnMowerSpeed(600) {}
	bool ZombieCollided(Zombie& zombie);
	void moveLawnMower(float deltaTime);
};

