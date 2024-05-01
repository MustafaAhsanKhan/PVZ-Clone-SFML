#include "SunFlower.h"


SunFlower::SunFlower()
{
    sungen_rate = 10;
    Suncost = 50; // cost 
}

sf::Sprite& SunFlower::getplantSprite()
{
    return plantSprite;
}

void SunFlower::setAnimation() // change for sunflower
{
    if (animationClock.getElapsedTime().asMilliseconds() > 300)
    {
        sf::IntRect textureRect = this->getplantSprite().getTextureRect();
        if (textureRect.left >= 251)
        {
            textureRect.left = 101.9; // for sunflowers spritesheet
        }
        else
        {
            textureRect.left += 30;
        }
        this->getplantSprite().setTextureRect(textureRect);
        animationClock.restart();
    }
}

//void SunFlower::setSunClock(float clock)
//{
//    sungen_rate = clock;
//}