#pragma once
#include "Plant.h"

class WallNut : public Plant
{
public:
	WallNut();

	virtual void setAnimation();

	virtual sf::Sprite& getplantSprite();
};

