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
	sf::Sprite plantSprite;
	sf::Clock animationClock;
public:
	Plant();
	virtual void setAnimation();
	virtual sf::Sprite& getPlantSprite();
	virtual void setXgridCoordinate(int x);
	virtual void setYgridCoordinate(int y);
	virtual int getXgridCoordinate();
	virtual int getYgridCoordinate();
    // virtual void setSunClock(float clock); 
};