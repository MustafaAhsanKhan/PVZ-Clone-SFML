#include "WallNut.h"

Wallnut::Wallnut()
{
    Suncost = 50; // cost 
    plantExists = false;
    XgridCoordinate = 0;
    YgridCoordinate = 0;
}

sf::Sprite& Wallnut::getPlantSprite()
{
    return plantSprite;
}

void Wallnut::Act() // change for sunflower
{
    if (animationClock.getElapsedTime().asMilliseconds() > 300)
    {
        sf::IntRect textureRect = this->getPlantSprite().getTextureRect();
        if (textureRect.left >= 250.8)
        {
            textureRect.left = 101.9; // for sunflowers spritesheet
        }
        else
        {
            textureRect.left += 30;
        }
        this->getPlantSprite().setTextureRect(textureRect);
        animationClock.restart();
    }
}

void Wallnut::setXgridCoordinate(int x)
{
    XgridCoordinate = x;
}
void Wallnut::setYgridCoordinate(int y)
{
    YgridCoordinate = y;
}
int Wallnut::getXgridCoordinate()
{
    return XgridCoordinate;
}
int Wallnut::getYgridCoordinate()
{
    return YgridCoordinate;
}

void Wallnut::setExists(bool ex)
{
    plantExists = ex;
}

bool Wallnut::exists()
{
    return plantExists;
}