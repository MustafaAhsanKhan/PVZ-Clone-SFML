#include "ZombieFactory.h"

ZombieFactory::ZombieFactory()
{
	zombieTypes = 5;
	MAX_ZOMBIES = 50;
	zombies = new Zombie * [zombieTypes];
	zombies[0] = new SimpleZombie[MAX_ZOMBIES];
	zombies[1] = new FlyingZombie[MAX_ZOMBIES];
	zombies[2] = new FootballZombie[MAX_ZOMBIES];
	zombies[3] = new DancingZombie[MAX_ZOMBIES];
	zombies[4] = new BackupDancerZombie[MAX_ZOMBIES];
}

ZombieFactory::ZombieFactory(int p_MAX_ZOMBIES)
{
	zombieTypes = 5;
	MAX_ZOMBIES = p_MAX_ZOMBIES;
	zombies = new Zombie * [zombieTypes];

	zombies[0] = new SimpleZombie[MAX_ZOMBIES];
	zombies[1] = new FlyingZombie[MAX_ZOMBIES];
	zombies[2] = new FootballZombie[MAX_ZOMBIES];
	zombies[3] = new DancingZombie[MAX_ZOMBIES];
	zombies[4] = new BackupDancerZombie[MAX_ZOMBIES];
}

Zombie& ZombieFactory::getZombie(int row, int col)
{
	return zombies[row][col];
}

int ZombieFactory::getMAX_ZOMBIES()
{
	return MAX_ZOMBIES;
}

ZombieFactory::~ZombieFactory()
{
	for (int i = 0; i < zombieTypes; i++)
	{
		delete[] zombies[i];
	}
	delete[] zombies;
}