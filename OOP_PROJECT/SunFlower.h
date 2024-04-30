#pragma once
#include "Plant.h"
class SunFlower : public Plant
{
private:
	sf::Clock sungen_rateclock;
	float sungen_rate;
public:
	SunFlower();
	virtual void setAnimation();
	virtual sf::Sprite& getplantSprite();
	// virtual void setsunclock(float clock);
};

