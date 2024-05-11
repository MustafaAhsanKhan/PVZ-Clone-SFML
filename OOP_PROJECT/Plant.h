#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
using namespace std;

class Plant
{
protected:
	int XgridCoordinate, YgridCoordinate;
	int Suncost;
	bool isAlive;
	bool isUnlocked;
	bool plantExists;
	sf::Sprite plantSprite;
	sf::Clock animationClock;
public:
	virtual void setExists(bool ex) = 0;
	virtual bool exists() = 0;
	virtual void Act() = 0;
	virtual sf::Sprite& getPlantSprite() = 0;
	virtual void setXgridCoordinate(int x) = 0;
	virtual void setYgridCoordinate(int y) = 0;
	virtual int getXgridCoordinate() = 0;
	virtual int getYgridCoordinate() = 0;
};