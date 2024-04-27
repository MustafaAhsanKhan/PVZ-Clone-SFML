#pragma once
#include<iostream>

#include<SFML/Graphics.hpp>
#include "Plant.h"

class PeaShooter : public Plant
{

public:
	PeaShooter() {}

	virtual sf::Sprite& getplantSprite();
	
};