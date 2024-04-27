#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
using namespace sf;
#include "Plant.h"

class PeaShooter : public Plant
{

public:
	PeaShooter() {}

	virtual Sprite& getplantSprite();

	// virtual void drawPlant();
	
};

