#pragma once
#include <SFML/Graphics.hpp>

class BulletPea
{
private:
	sf::Sprite bulletSprite;
	int x_pos;
	int y_pos;
	int damage;
	int bulletSpeed;
	bool exists;

public:
	// Getters
	int getBulletSpeed();
	int getDamage();
	int getXPos();
	int getYPos();
	bool getExists();
	sf::Sprite& getBulletSprite();

	// Setters
	void setBulletSpeed(int speed);
	void setDamage(int damage);
	void setXPos(int x);
	void setYPos(int y);
	void setExists(bool exists);

	// Functions to handle the bullet

	void shoot(int XgridCoordinate, int YgridCoordinate);

	void move();

	void drawBullet(sf::RenderWindow& window);
};