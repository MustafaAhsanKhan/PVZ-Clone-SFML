#include "SunFlower.h"


//SunFlower::SunFlower()
//{
//    SunGen_rate = 10; // time 
//    Suncost = 50; // cost 
//}
//
//sf::Sprite& SunFlower::getplantSprite()
//{
//    return plantSprite;
//}
//
//void SunFlower::setAnimation()
//{
//    if (PS_animationClock.getElapsedTime().asMilliseconds() > 300)
//    {
//        sf::IntRect textureRect = this->getplantSprite().getTextureRect();
//        if (textureRect.left >= 188.75)
//        {
//            textureRect.left = 0;
//        }
//        else
//        {
//            textureRect.left += 27.25;
//        }
//        this->getplantSprite().setTextureRect(textureRect);
//        PS_animationClock.restart();
//    }
//}
//
//void SunFlower::setSunClock(float clock)
//{
//    SunGen_rate = clock;
//}