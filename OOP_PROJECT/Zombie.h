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
	sf::Clock zombie_damage_clock;
	sf::Clock animationClock;

public:
	Zombie();
	virtual sf::Sprite& getZombieSprite();
	virtual int getXgridCoordinate();
	virtual int getYgridCoordinate();
	virtual void setXgridCoordinate(float);
	virtual void setYgridCoordinate(float);
	virtual float getx_pos();
	virtual float gety_pos();
	virtual void setx_pos(float);
	virtual void sety_pos(float);
	virtual void damagePlant(Plant&);
	virtual int getZombieHealth();
	virtual void setAnimation();
	virtual void moveZombie(float deltaTime);

};

