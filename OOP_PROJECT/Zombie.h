#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include "Plant.h"

class Zombie
{
protected:
	sf::Sprite ZombieSprite;
	int ZombieHealth;
	float x_pos, y_pos;
	int zombieSpeed;
	int damage;
	bool is_Slowed;
	sf::Clock zombie_damage_clock;

public:
	Zombie();
	virtual int getZombieHealth();
	virtual sf::Sprite& getZombieSprite();
	virtual float getXcoordinate();
	virtual float getYcoordinate();
	virtual void damagePlant(Plant&);
};

