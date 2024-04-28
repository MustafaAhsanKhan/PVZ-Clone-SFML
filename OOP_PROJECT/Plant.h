#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
using namespace std;

class Plant
{
protected:
	int Xgridcoordinate, Ygridcoordinate; 
	int Suncost;
	bool isAlive;
	bool isUnlocked;
	sf::Sprite plantSprite;
	sf::Clock PS_animationClock;
public:
	Plant();	
	virtual void setAnimation();
	virtual sf::Sprite& getPlantSprite();
	virtual void setXgridcoordinate(int x);
	virtual void setYgridcoordinate(int y);
	virtual int getXgridcoordinate();
	virtual int getYgridcoordinate();
    //virtual void setSunClock(float clock);
};