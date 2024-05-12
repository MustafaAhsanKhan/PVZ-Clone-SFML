#include "SunFlower.h"


SunFlower::SunFlower()
{
    sun = new Sun;
    plantExists = false;
}

sf::Sprite& SunFlower::getPlantSprite()
{
    return plantSprite;
}

void SunFlower::Act() // change for sunflower
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

    if (sunClock.getElapsedTime().asSeconds() > 20)
    {
        sun->setExists(true);
        sun->getSunSprite().setPosition(XgridCoordinate * 100.66 + 315, YgridCoordinate * 114 + 110);   
        sun->setXpos(XgridCoordinate * 100.66 + 315);
        sun->setYpos(YgridCoordinate * 114 + 110);
    }

    // if sun collected, restart the clock

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
    sunClock.restart();
    plantExists = ex;
}

bool SunFlower::exists()
{
    return plantExists;
}

void SunFlower::setSunClock()
{

}
Sun*& SunFlower::getSun()
{
    return sun;
}

void SunFlower::drawSun(sf::RenderWindow& window, int &sunsNum, sf::Sound& sound)
{
    if (sun->getExists())
    {
        window.draw(sun->getSunSprite());
    }
   
    // handling the input
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        sf::Vector2f mousePosition(sf::Mouse::getPosition(window));
        if (mousePosition.x >= sun->getXpos() && mousePosition.x <= sun->getXpos() + (250 * 0.375) && mousePosition.y >= sun->getYpos() && mousePosition.y <= sun->getYpos() + (250 * 0.375))
        {
            sound.play();
            sun->setExists(false);
            sunsNum += 50;
            sunClock.restart();
        }

    }
}