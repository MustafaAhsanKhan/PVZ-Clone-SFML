#include<iostream>
using namespace std;
#include "Plant.h"
#include "AssetManager.h"
#include <SFML/Graphics.hpp>

Plant::Plant()
{
	
}

Sprite& Plant::getplantSprite()
{
	return plantSprite;
}