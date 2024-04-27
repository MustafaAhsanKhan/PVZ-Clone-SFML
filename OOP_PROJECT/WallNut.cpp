#include "WallNut.h"

sf::Sprite& WallNut::getplantSprite()
{
    return plantSprite;
}


void WallNut::setAnimation()
{
    if (PS_animationClock.getElapsedTime().asMilliseconds() > 300)
    {
        sf::IntRect textureRect = this->getplantSprite().getTextureRect();
        if (textureRect.left >= 188.75)
        {
            textureRect.left = 0;
        }
        else
        {
            textureRect.left += 27.25;
        }
        this->getplantSprite().setTextureRect(textureRect);
        PS_animationClock.restart();
    }
}
