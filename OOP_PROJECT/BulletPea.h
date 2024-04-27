#pragma once
#include <SFML/Graphics.hpp>

class BulletPea
{
private:
	sf::Sprite bulletSprite;
	int x_pos;
	int y_pos;
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
	void move(); // increment position at a constant rate (bullet speed will be constant)
	void drawBullet(sf::RenderWindow& window);
};