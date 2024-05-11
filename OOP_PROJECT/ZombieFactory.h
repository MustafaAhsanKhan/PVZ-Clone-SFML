#pragma once
#include "Zombie.h"
#include "SimpleZombie.h"
#include "FlyingZombie.h"
#include "FootballZombie.h"
#include "DancingZombie.h"
#include "DolphinRiderZombie.h"

class ZombieFactory
{
private:
	Zombie** zombies;
	int MAX_ZOMBIES;
	int zombieTypes;

public:
	ZombieFactory();
	ZombieFactory(int p_MAX_ZOMBIES);
	Zombie& getZombie(int row, int col);
	int getMAX_ZOMBIES();
	~ZombieFactory();
};