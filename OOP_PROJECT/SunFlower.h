#pragma once
#include "Plant.h"
class SunFlower : public Plant
{
private:
	int Sungenerationrate;
public:
	SunFlower();

	virtual void setAnimation();

	virtual sf::Sprite& getplantSprite();
};

