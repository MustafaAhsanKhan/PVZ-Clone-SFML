#include "LawnMower.h"

bool LawnMower::ZombieCollided(Zombie& zombie)
{
	return (abs(zombie.getXgridCoordinate() - LawnMower::x_pos) < 10);
}
void LawnMower::moveLawnMower(float deltaTime)
{
	lawnMowerSpeed += lawnMowerSpeed * deltaTime;
	
	

}