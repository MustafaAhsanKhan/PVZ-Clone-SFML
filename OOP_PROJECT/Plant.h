#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include "Sun.h"
#include <SFML/Audio.hpp>
using namespace std;

class Plant
{
protected:
	int XgridCoordinate, YgridCoordinate;
	bool isAlive;
	bool isUnlocked;
	bool plantExists;
	int plantHealth;
	sf::Sprite plantSprite;
	sf::Clock animationClock;
	Sun* sun;
	sf::Clock sunClock;
public:
	virtual void setExists(bool ex) = 0;
	virtual bool exists() = 0;
	virtual void Act() = 0;
	virtual sf::Sprite& getPlantSprite() = 0;
	virtual void setXgridCoordinate(int x) = 0;
	virtual void setYgridCoordinate(int y) = 0;
	virtual int getXgridCoordinate() = 0;
	virtual int getYgridCoordinate() = 0;
	virtual int getPlantHealth() = 0;
	virtual void operator-=(int damage) = 0;
	virtual Sun*& getSun() = 0;
	virtual void drawSun(sf::RenderWindow& window, int &sunsNum, sf::Sound& sound) = 0;
};