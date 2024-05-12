#include "Bullet.h"


Bullet::Bullet()
{
	this->x_pos = 0;
	this->y_pos = 0;
	this->damage = 30; // change according to game
	this->exists = false; // initially false  
	/*
	this variable is only to check if the bullet should draw or not. 
	Its not going to depend on the rate at which the plant shoots. 
	Hence when the bullet becomes false we just need to set its position back to the plant's
	*/
	this->bulletSpeed = 400; // change to whatever speed
}
// Getters
float Bullet::getBulletSpeed()
{
	return bulletSpeed;
}
int Bullet::getDamage()
{
	return damage;
}
float Bullet::getXPos()
{
	return x_pos;
}
float Bullet::getYPos()
{
	return y_pos;
}
bool Bullet::getExists()
{
	return exists;
}

sf::Sprite& Bullet::getBulletSprite()
{
	return bulletSprite;
}


void Bullet::setDamage(int damage)
{
	this->damage = damage;
}
void Bullet::setXPos(int x)
{
	x_pos = x;
}
void Bullet::setYPos(int y)
{
	y_pos = y;
}
void Bullet::setExists(bool exists)
{
	this->exists = exists;
}

void Bullet::move(float deltaTime)
{
	x_pos += bulletSpeed * deltaTime;	
	if (x_pos > 1300)
	{
		exists = false;
	}
}

void Bullet::drawBullet(sf::RenderWindow& window)
{
	bulletSprite.setPosition(x_pos, y_pos);
	if (exists)
	{
		window.draw(bulletSprite); // only draws when the bullet exists
	}
	
}

void Bullet::setBulletSpeed(int sp)
{
	bulletSpeed = sp;
}

bool Bullet::isColliding(Zombie& zombie)
{
	return bulletSprite.getGlobalBounds().intersects(zombie.getZombieSprite().getGlobalBounds());
	// return (abs(Bullet::x_pos - zombie.getx_pos()) <= 1 && abs(Bullet::y_pos - zombie.gety_pos() < 200));
} 

void Bullet::damageZombie(Zombie& zombie)
{
	if (isColliding(zombie))
	{
		zombie -= damage;
		cout << zombie.getExists();
		cout << "Health: " << zombie.getZombieHealth() << endl;

		cout << "Collided! " << endl;
		Bullet::exists = false;
	}
}