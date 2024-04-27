#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
using namespace std;

class Plant
{
protected:
	int gridcoordinateX, gridcoordinateY; 
	int Suncost;
	bool isAlive;
	bool isUnlocked;
	sf::Sprite plantSprite;
	sf::Clock PS_animationClock;
public:
	Plant();

	virtual void setAnimation();
	
	virtual sf::Sprite& getplantSprite();

};