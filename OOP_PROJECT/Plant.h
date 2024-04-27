#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Plant
{
protected:
	int x_pos, y_pos; 
	int Suncost;
	bool isAlive;
	bool isUnlocked;
	Sprite plantSprite;

public:
	Plant();

	virtual Sprite& getplantSprite();

	// virtual void drawPlant();

};

