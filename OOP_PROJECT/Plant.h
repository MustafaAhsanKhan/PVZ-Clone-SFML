#pragma once
using namespace std;

#include <SFML/Graphics.hpp>

class Plant
{
protected:
	int x_pos, y_pos; 
	int Suncost;
	bool isAlive;
	bool isUnlocked;
	sf::Sprite plantSprite;

public:
	Plant();


};