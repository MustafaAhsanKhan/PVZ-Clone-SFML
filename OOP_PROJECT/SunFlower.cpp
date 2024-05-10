#include "SunFlower.h"


SunFlower::SunFlower()
{
    Suncost = 50; // cost 
    plantExists = false;
    XgridCoordinate = 0;
    YgridCoordinate = 0;
}

sf::Sprite& SunFlower::getPlantSprite()
{
    return plantSprite;
}

void SunFlower::setAnimation() // change for sunflower
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

void SunFlower::setXgridCoordinate(int x)
{
    XgridCoordinate = x;
}
void SunFlower::setYgridCoordinate(int y)
{
    YgridCoordinate = y;
}
int SunFlower::getXgridCoordinate()
{
    return XgridCoordinate;
}
int SunFlower::getYgridCoordinate()
{
    return YgridCoordinate;
}

void SunFlower::setExists(bool ex)
{
    plantExists = ex;
}

bool SunFlower::exists()
{
    return plantExists;
}