#include "PeaShooter.h"
#include<iostream>
#include<SFML/Graphics.hpp>
using namespace sf;


Sprite& PeaShooter::getplantSprite()
{
	cout << "peashooter class";
	return plantSprite;

}

//void PeaShooter::drawPlant()