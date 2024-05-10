#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Bullet
{
private:
	sf::Sprite bulletSprite;
	float x_pos;
	float y_pos;
	int damage;
	float bulletSpeed;
	bool exists;

public:
	Bullet();
	// Getters
	float getBulletSpeed();
	int getDamage();
	float getXPos();
	float getYPos();
	bool getExists();
	sf::Sprite& getBulletSprite();


	// Setters
	void setDamage(int damage);
	void setXPos(int x);
	void setYPos(int y);
	void setExists(bool exists);
	void setBulletSpeed(int sp);

	// Functions to handle the bullet
	void move(float deltaTime); // increment position at a constant rate (bullet speed will be constant)
	void drawBullet(sf::RenderWindow& window);
};