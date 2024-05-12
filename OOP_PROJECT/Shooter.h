#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include "Plant.h"
#include "Bullet.h"

class Shooter : public Plant
{
protected:
	int MAX_BULLETS;
	sf::Clock ShootingRateClock;
	float ShootingRate;
	Bullet* bullets;
public:
	virtual Bullet& getBullet(int index) = 0;
	virtual int getMaxBullets() = 0;
	virtual void setExists(bool ex) = 0; // sets existence of the plant
	virtual bool exists() = 0; // checks if it exists (returns plantExists data member)
	virtual void shootBullet(float deltaTime) = 0;
	virtual void Act() = 0;
	virtual sf::Sprite& getPlantSprite() = 0;
	virtual void setXgridCoordinate(int x) = 0;
	virtual void setYgridCoordinate(int y) = 0;
	virtual int getXgridCoordinate() = 0;
	virtual int getYgridCoordinate() = 0;
	virtual Sun*& getSun() = 0;
	virtual void drawSun(sf::RenderWindow& window, int &sunsNum, sf::Sound& sound) = 0;
	~Shooter() { delete[] bullets; }

};