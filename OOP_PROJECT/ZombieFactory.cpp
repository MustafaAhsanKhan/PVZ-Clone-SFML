#include "ZombieFactory.h"

//ZombieFactory::ZombieFactory()
//{
//	MAX_ZOMBIES = p_MAX_ZOMBIES;
//	zombies = new Zombie * [zombieTypes];
//	zombies[0] = new SimpleZombie[MAX_ZOMBIES];
//}

ZombieFactory::ZombieFactory(int p_MAX_ZOMBIES)
{
	zombieTypes = 4;
	MAX_ZOMBIES = p_MAX_ZOMBIES;
	zombies = new Zombie * [zombieTypes];

	zombies[0] = new SimpleZombie[MAX_ZOMBIES];
	zombies[1] = new FlyingZombie[MAX_ZOMBIES];
	zombies[2] = new FootballZombie[MAX_ZOMBIES];
	zombies[3] = new DancingZombie[MAX_ZOMBIES];
}

Zombie& ZombieFactory::getZombie(int row, int col)
{
	return zombies[row][col];
}

ZombieFactory::~ZombieFactory()
{
	for (int i = 0; i < zombieTypes; i++)
	{
		delete[] zombies[i];
	}
	delete[] zombies;
}