#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include "Plant.h"

class Zombie
{
protected:
	sf::Sprite ZombieSprite;
	int ZombieHealth;
	int XgridCoordinate, YgridCoordinate;
	float x_pos, y_pos;
	int zombieSpeed;
	int damagePerSec;
	bool is_Slowed;
	bool Exists;
	sf::Clock zombie_damage_clock;
	sf::Clock animationClock;
	bool movingUp;
	sf::Clock moveClock;

public:
	Zombie() {}
	virtual sf::Sprite& getZombieSprite() = 0;
	virtual int getXgridCoordinate() = 0;
	virtual int getYgridCoordinate() = 0;
	virtual void setXgridCoordinate(float) = 0;
	virtual void setYgridCoordinate(float) = 0;
	virtual float getx_pos() = 0;
	virtual float gety_pos() = 0;
	virtual bool getExists() = 0;
	virtual void setx_pos(float) = 0;
	virtual void sety_pos(float) = 0;
	virtual void setExists(bool) = 0;
	virtual void damagePlant(Plant&) = 0;
	virtual int getZombieHealth() = 0;
	virtual void setAnimation() = 0;
	virtual void moveZombie(float deltaTime) = 0;

};

