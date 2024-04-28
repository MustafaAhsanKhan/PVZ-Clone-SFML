#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class BulletPea
{
private:
	sf::Sprite bulletSprite;
	float x_pos;
	float y_pos;
	int damage;
	float bulletSpeed;
	bool exists;

public:
	BulletPea();
	// Getters
	float getBulletSpeed();
	int getDamage();
	int getXPos();
	int getYPos();
	bool getExists();
	sf::Sprite& getBulletSprite();


	// Setters
	void setDamage(int damage);
	void setXPos(int x);
	void setYPos(int y);
	void setExists(bool exists);

	// Functions to handle the bullet
	void move(float deltaTime); // increment position at a constant rate (bullet speed will be constant)
	void drawBullet(sf::RenderWindow& window);
};