#include "Level1State.h"

Level1State::Level1State()
{
	// Sounds
	backgroundMusic.openFromFile("../Sounds/backgroundmusic.ogg");
	backgroundMusic.setVolume(5); // change later
	//backgroundMusic.play();
	zombieWaveBuffer.loadFromFile("../Sounds/zombiesarecoming.ogg");
	zombieWave.setBuffer(zombieWaveBuffer);
	zombieWave.setVolume(90);

	// backgroundMusic.pause();
	sungen_SoundBuffer.loadFromFile("../Sounds/plants-vs-zombies-sun-pickup.ogg");
	sungen_Sound.setBuffer(sungen_SoundBuffer);
	sungen_Sound.setVolume(90);
	placingPlantSoundBuffer.loadFromFile("../Sounds/plantplacingsound.ogg");
	placingPlantSound.setBuffer(placingPlantSoundBuffer);
	placingPlantSound.setVolume(15);

	// Fonts
	sunsNum = 5000;  // This is the currency
	font.loadFromFile("../Fonts/Wedges.ttf");
	sunsNumText.setFont(font);
	sunsNumText.setCharacterSize(50); // Set font size
	sunsNumText.setFillColor(sf::Color::White);
	sunsNumText.setPosition(107, 20);
	sunsNumText.setString(std::to_string(sunsNum));
	elapsedTimeText.setFont(font);
	elapsedTimeText.setCharacterSize(45); // Set font size
	elapsedTimeText.setFillColor(sf::Color::White);
	elapsedTimeText.setPosition(500, 20);
	int minutes = static_cast<int>(ElapsedTime.getElapsedTime().asSeconds()) / 60;
	int seconds = static_cast<int>(ElapsedTime.getElapsedTime().asSeconds()) % 60;
	string time = minutes + ":" + seconds;
	elapsedTimeText.setString(time);
	// shovel sprite
	clickedShovel = false;

	// Sun
	sunCount = 10;
	suns = new Sun[sunCount];
	lawnmowers = new LawnMower[MAX_lawnmowers];




	// Initializing field game status (all grids are currently empty)
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			FIELD_GAME_STATUS[i][j] = false;  // Initially all the grid is empty
		}
	}

	// No plant seed packet has been clicked yet
	for (int i = 0; i < totalPlantTypes; i++)
	{
		clickedSeedPacket[i] = false;
	}

    // srand(time(0));
    for (int i = 0; i < 5; i++)  // This controls the type of zombie
    {
        for (int j = 0; j < AllZombies.getMAX_ZOMBIES(); j++)  // This controls the number of zombies
        {
            int temp = rand() % 5;
            AllZombies.getZombie(i, j).setXgridCoordinate(8);
            AllZombies.getZombie(i, j).setYgridCoordinate(temp);
            AllZombies.getZombie(i, j).setx_pos(1180);
            AllZombies.getZombie(i, j).sety_pos((120 * temp) + 40);
        }
    }

}

void Level1State::setPlantFactoryTextures(AssetManager& Assets)
{
	textureRect = sf::IntRect(0, 0, 27.125, 31);  // initially works for normal peashooter
	int totalShooterTypes = 3;

	// SHOOTERS
	// Peashooter
	for (int i = 0; i < 50; i++) // 50 plants
	{
		AllPlants.getShooter(0, i).getPlantSprite().setTexture(Assets.getTexture(2));
		AllPlants.getShooter(0, i).getPlantSprite().setTextureRect(textureRect);
		AllPlants.getShooter(0, i).getPlantSprite().setScale(3, 3);
	}

	// Repeater
	textureRect = sf::IntRect(0, 0, 34, 34);
	for (int i = 0; i < 50; i++) // 50 plants
	{
		AllPlants.getShooter(1, i).getPlantSprite().setTexture(Assets.getTexture(5));
		AllPlants.getShooter(1, i).getPlantSprite().setTextureRect(textureRect);
		AllPlants.getShooter(1, i).getPlantSprite().setScale(3, 3);
	}
	// SnowPea
	textureRect = sf::IntRect(0, 0, 30.25, 31);
	for (int i = 0; i < 50; i++) // 50 plants
	{
		AllPlants.getShooter(2, i).getPlantSprite().setTexture(Assets.getTexture(6));
		AllPlants.getShooter(2, i).getPlantSprite().setTextureRect(textureRect);
		AllPlants.getShooter(2, i).getPlantSprite().setScale(3, 3);
	}
	// Fumeshroom
	textureRect = sf::IntRect(0, 0, 34.8, 33);
	for (int i = 0; i < 50; i++) // 50 plants
	{
		AllPlants.getShooter(3, i).getPlantSprite().setTexture(Assets.getTexture(8));
		AllPlants.getShooter(3, i).getPlantSprite().setTextureRect(textureRect);
		AllPlants.getShooter(3, i).getPlantSprite().setScale(3, 3);
	}


	// The shooter bullets
	textureRect = sf::IntRect(78, 38, 10, 15);
	int bullettextureindex = 4;

	for (int type = 0; type < totalShooterTypes - 1; type++)
	{
		for (int i = 0; i < 50; i++)
		{
			for (int j = 0; j < AllPlants.getShooter(type, i).getMaxBullets(); j++)
			{
				AllPlants.getShooter(type, i).getBullet(j).getBulletSprite().setTexture(Assets.getTexture(7));
				AllPlants.getShooter(type, i).getBullet(j).getBulletSprite().setScale(3, 3);
				AllPlants.getShooter(type, i).getBullet(j).getBulletSprite().setTextureRect(textureRect);
			}
		}
	}

	// Snow pea bullet 
	textureRect = sf::IntRect(90, 50.95, 23, 13);
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < AllPlants.getShooter(2, i).getMaxBullets(); j++)
		{
			AllPlants.getShooter(2, i).getBullet(j).getBulletSprite().setTexture(Assets.getTexture(6));
			AllPlants.getShooter(2, i).getBullet(j).getBulletSprite().setScale(3, 3);
			AllPlants.getShooter(2, i).getBullet(j).getBulletSprite().setTextureRect(textureRect);
		}
	}
	// Fumeshroom bullet
	textureRect = sf::IntRect(0, 106, 34, 16);
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < AllPlants.getShooter(3, i).getMaxBullets(); j++)
		{
			AllPlants.getShooter(3, i).getBullet(j).getBulletSprite().setTexture(Assets.getTexture(8));
			AllPlants.getShooter(3, i).getBullet(j).getBulletSprite().setScale(3, 3);
			AllPlants.getShooter(3, i).getBullet(j).getBulletSprite().setTextureRect(textureRect);
		}
	}

	// NORMAL PLANTS
	textureRect = sf::IntRect(101.9, 36.75, 30, 32); // sunflower
	for (int i = 0; i < 50; i++) // 50 plants
	{
		AllPlants.getNormalPlant(0, i).getPlantSprite().setTexture(Assets.getTexture(1));
		AllPlants.getNormalPlant(0, i).getPlantSprite().setTextureRect(textureRect);
		AllPlants.getNormalPlant(0, i).getPlantSprite().setScale(3, 3);
		// Setting sun textures for sunflower
		AllPlants.getNormalPlant(0, i).getSun()->getSunSprite().setTexture(Assets.getTexture(33));
		AllPlants.getNormalPlant(0, i).getSun()->getSunSprite().setScale(0.375, 0.375);
	}

	textureRect = sf::IntRect(0, 92, 28.75, 34); // Wallnut
	for (int i = 0; i < 50; i++) // 50 plants
	{
		AllPlants.getNormalPlant(1, i).getPlantSprite().setTexture(Assets.getTexture(3));
		AllPlants.getNormalPlant(1, i).getPlantSprite().setTextureRect(textureRect);
		AllPlants.getNormalPlant(1, i).getPlantSprite().setScale(3, 3);
	}
	textureRect = sf::IntRect(69, 0, 47, 40); // Cherrybomb
	for (int i = 0; i < 50; i++) // 50 plants
	{
		AllPlants.getNormalPlant(2, i).getPlantSprite().setTexture(Assets.getTexture(4));
		AllPlants.getNormalPlant(2, i).getPlantSprite().setTextureRect(textureRect);
		AllPlants.getNormalPlant(2, i).getPlantSprite().setScale(2.25, 2.25);
	}

}

void Level1State::setZombieTextures(AssetManager& Assets)
{
	textureRect = sf::IntRect(5, 65.28, 35.11, 48.28);  // SimpleZombie
	for (int i = 0; i < AllZombies.getMAX_ZOMBIES(); i++)
	{
		AllZombies.getZombie(0, i).getZombieSprite().setTexture(Assets.getTexture(10));
		AllZombies.getZombie(0, i).getZombieSprite().setTextureRect(textureRect);
		AllZombies.getZombie(0, i).getZombieSprite().setScale(3, 3);
	}

	textureRect = sf::IntRect(0, 0, 34.95, 59);  // FlyingZombie
	for (int i = 0; i < AllZombies.getMAX_ZOMBIES(); i++)
	{
		AllZombies.getZombie(1, i).getZombieSprite().setTexture(Assets.getTexture(11));
		AllZombies.getZombie(1, i).getZombieSprite().setTextureRect(textureRect);
		AllZombies.getZombie(1, i).getZombieSprite().setScale(2.5,2.5);
	}

	textureRect = sf::IntRect(0, 76.74, 64, 60.74);  // FootballZombie
	for (int i = 0; i < AllZombies.getMAX_ZOMBIES(); i++)
	{
		AllZombies.getZombie(2, i).getZombieSprite().setTexture(Assets.getTexture(12));
		AllZombies.getZombie(2, i).getZombieSprite().setTextureRect(textureRect);
		AllZombies.getZombie(2, i).getZombieSprite().setScale(2.5, 2.5);
	}

    textureRect = sf::IntRect(5, 85, 56, 74);  // DancingZombie
    for (int j = 0; j < AllZombies.getMAX_ZOMBIES(); j++)
    {
        AllZombies.getZombie(3, j).getZombieSprite().setTexture(Assets.getTexture(13));
        AllZombies.getZombie(3, j).getZombieSprite().setTextureRect(textureRect);
        AllZombies.getZombie(3, j).getZombieSprite().setScale(2.2, 2.2);
    }

    textureRect = sf::IntRect(5, 90, 56, 64);  // BackupDancerZombie
    for (int i = 0; i < AllZombies.getMAX_ZOMBIES(); i++)
    {
        AllZombies.getZombie(4, i).getZombieSprite().setTexture(Assets.getTexture(14));
        AllZombies.getZombie(4, i).getZombieSprite().setTextureRect(textureRect);
        AllZombies.getZombie(4, i).getZombieSprite().setScale(2.2, 2.2);
    }
 }

void Level1State::setUITextures(AssetManager& Assets)
{
	sf::IntRect textureRect(0, 45, 143, 675);

	// Seed packet sprite
	seedPacketSprite.setTexture(Assets.getTexture(30));
	seedPacketSprite.setTextureRect(textureRect);
	seedPacketSprite.setPosition(45, 100);
	seedPacketSprite.setScale(0.9, 0.9);

	// Lawn mowers
	for (int i = 0; i < MAX_lawnmowers; i++)
	{
		lawnmowers[i].getLawnMowerSprite().setTexture(Assets.getTexture(31));
		lawnmowers[i].getLawnMowerSprite().setScale(0.28, 0.28);
		lawnmowers[i].getLawnMowerSprite().setPosition(220, (i * 117.5) + 120);
		lawnmowers[i].setX_pos(220);
		lawnmowers[i].setY_pos((i * 117.5) + 120);
	}

	// Suns 
	// Suns 
	for (int i = 0; i < sunCount; i++)
	{
		suns[i].getSunSprite().setTexture(Assets.getTexture(33));
		suns[i].getSunSprite().setScale(0.375, 0.375);
	}

	/*for (int i = 0; i < 50; i++)
	{
		sunflowerSun[i].getSunSprite().setTexture(Assets.getTexture(33));
		sunflowerSun[i].getSunSprite().setScale(0.375, 0.375);
	}*/


}

void Level1State::handleAllPlantsCreation(sf::RenderWindow& window)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		int gridX = 0;
		int gridY = 0;
		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
		gridX = (mousePosition.x / 100.66) - 3;
		gridY = (mousePosition.y / 114) - 1;

		/*
		-----TEXTURE AND CLICKEDSEEDPACKET ARRAY INDEXES-----

		* sunflower index : 1
		* peashooter index : 2
		* Wallnut index: 3
		* Cherrybomb index: 4
		* Repeater index: 5
		* Snow Pea index: 6
		Fumeshroom index: 7

		*/

		// checks if seed packet clicked
		for (int i = 0; i < totalPlantTypes; ++i)
		{

			if (mousePosition.x > 50 && mousePosition.x <= 168 && mousePosition.y >= (109 + (i * 81.42)) && mousePosition.y <= (109 + ((i + 1) * 81.42)))
			{
				for (int j = 0; j < totalPlantTypes; j++)  // We selected another seed packet
				{
					clickedSeedPacket[j] = false;
				}

				clickedSeedPacket[i] = true;
			}

			if (mousePosition.x >= 305 && mousePosition.x < 1175 && mousePosition.y >= 125 && mousePosition.y < 660 && clickedSeedPacket[i] == true && FIELD_GAME_STATUS[gridY][gridX] == false)
			{
				switch (i)
				{
				case 0:

					if (sunsNum >= 50)
					{
						sunflowerInstances++; // increment
						sunsNum -= 50;
						sunsNumText.setString(std::to_string(sunsNum));
						placingPlantSound.play();
						AllPlants.getNormalPlant(0, totalNormalPlantInstancesCreated - 1).getPlantSprite().setPosition(gridX * 100.66 + 315, gridY * 114 + 110);
						AllPlants.getNormalPlant(0, totalNormalPlantInstancesCreated - 1).setXgridCoordinate(gridX);
						AllPlants.getNormalPlant(0, totalNormalPlantInstancesCreated - 1).setYgridCoordinate(gridY);
						AllPlants.getNormalPlant(0, totalNormalPlantInstancesCreated - 1).setExists(true);
						totalNormalPlantInstancesCreated++;
						FIELD_GAME_STATUS[gridY][gridX] = true;  // So another plant cant be placed on the same spot
						clickedSeedPacket[i] = false;
					}
					break;


				case 1:

					if (sunsNum >= 100)
					{
						sunsNum -= 100;
						sunsNumText.setString(std::to_string(sunsNum));
						placingPlantSound.play();
						AllPlants.getShooter(0, totalShooterInstancesCreated - 1).getPlantSprite().setPosition(gridX * 100.66 + 315, gridY * 114 + 110);
						AllPlants.getShooter(0, totalShooterInstancesCreated - 1).setXgridCoordinate(gridX);
						AllPlants.getShooter(0, totalShooterInstancesCreated - 1).setYgridCoordinate(gridY);
						AllPlants.getShooter(0, totalShooterInstancesCreated - 1).setExists(true);
						totalShooterInstancesCreated++;
						FIELD_GAME_STATUS[gridY][gridX] = true;  // So another plant cant be placed on the same spot
						clickedSeedPacket[i] = false;
					}
					break;



				case 2:

					if (sunsNum >= 50)
					{
						sunsNum -= 50;
						sunsNumText.setString(std::to_string(sunsNum));
						placingPlantSound.play();
						AllPlants.getNormalPlant(1, totalNormalPlantInstancesCreated - 1).getPlantSprite().setPosition(gridX * 100.66 + 315, gridY * 114 + 110);
						AllPlants.getNormalPlant(1, totalNormalPlantInstancesCreated - 1).setXgridCoordinate(gridX);
						AllPlants.getNormalPlant(1, totalNormalPlantInstancesCreated - 1).setYgridCoordinate(gridY);
						AllPlants.getNormalPlant(1, totalNormalPlantInstancesCreated - 1).setExists(true);
						totalNormalPlantInstancesCreated++;;
						FIELD_GAME_STATUS[gridY][gridX] = true;  // So another plant cant be placed on the same spot
						clickedSeedPacket[i] = false;
					}
					break;


				case 3:

					if (sunsNum >= 150)
					{
						sunsNum -= 150;
						sunsNumText.setString(std::to_string(sunsNum));
						placingPlantSound.play();
						AllPlants.getNormalPlant(2, totalNormalPlantInstancesCreated - 1).getPlantSprite().setPosition(gridX * 100.66 + 315, gridY * 114 + 110);
						AllPlants.getNormalPlant(2, totalNormalPlantInstancesCreated - 1).setXgridCoordinate(gridX);
						AllPlants.getNormalPlant(2, totalNormalPlantInstancesCreated - 1).setYgridCoordinate(gridY);
						AllPlants.getNormalPlant(2, totalNormalPlantInstancesCreated - 1).setExists(true);
						totalNormalPlantInstancesCreated++;
						FIELD_GAME_STATUS[gridY][gridX] = true;  // So another plant cant be placed on the same spot
						clickedSeedPacket[i] = false;
					}
					break;


				case 4:

					if (sunsNum >= 200)
					{
						sunsNum -= 200;
						sunsNumText.setString(std::to_string(sunsNum));
						placingPlantSound.play();
						AllPlants.getShooter(1, totalShooterInstancesCreated - 1).getPlantSprite().setPosition(gridX * 100.66 + 305, gridY * 114 + 110);
						AllPlants.getShooter(1, totalShooterInstancesCreated - 1).setXgridCoordinate(gridX);
						AllPlants.getShooter(1, totalShooterInstancesCreated - 1).setYgridCoordinate(gridY);
						AllPlants.getShooter(1, totalShooterInstancesCreated - 1).setExists(true);
						totalShooterInstancesCreated++;
						FIELD_GAME_STATUS[gridY][gridX] = true;  // So another plant cant be placed on the same spot
						clickedSeedPacket[i] = false;
					}
					break;


				case 5:

					if (sunsNum >= 175)
					{
						sunsNum -= 175;
						sunsNumText.setString(std::to_string(sunsNum));
						placingPlantSound.play();
						AllPlants.getShooter(2, totalShooterInstancesCreated - 1).getPlantSprite().setPosition(gridX * 100.66 + 305, gridY * 114 + 110);
						AllPlants.getShooter(2, totalShooterInstancesCreated - 1).setXgridCoordinate(gridX);
						AllPlants.getShooter(2, totalShooterInstancesCreated - 1).setYgridCoordinate(gridY);
						AllPlants.getShooter(2, totalShooterInstancesCreated - 1).setExists(true);
						totalShooterInstancesCreated++;
						FIELD_GAME_STATUS[gridY][gridX] = true;  // So another plant cant be placed on the same spot
						clickedSeedPacket[i] = false;
					}
					break;


				case 6:

					if (sunsNum >= 75)
					{
						sunsNum -= 75;
						sunsNumText.setString(std::to_string(sunsNum));
						placingPlantSound.play();
						AllPlants.getShooter(3, totalShooterInstancesCreated - 1).getPlantSprite().setPosition(gridX * 100.66 + 305, gridY * 114 + 110);
						AllPlants.getShooter(3, totalShooterInstancesCreated - 1).setXgridCoordinate(gridX);
						AllPlants.getShooter(3, totalShooterInstancesCreated - 1).setYgridCoordinate(gridY);
						AllPlants.getShooter(3, totalShooterInstancesCreated - 1).setExists(true);
						totalShooterInstancesCreated++;
						FIELD_GAME_STATUS[gridY][gridX] = true;  // So another plant cant be placed on the same spot
						clickedSeedPacket[i] = false;
					}
					break;
				}
			}
		}
	}
}

void Level1State::spawnZombies()
{
	srand(time(nullptr));

	
	const int numWaves = 2;  // This variable stores the total number of waves.
	const int waveDurations[numWaves] = { 60, 60 };
	/*This array stores the duration of each wave in seconds. 
	For example, waveDurations[0] represents the duration of the first wave, 
	and waveDurations[1] represents the duration of the second wave, and so on.*/

	const int numZombieTypes[numWaves] = { 1, 2 };
	/*This array stores the number of different zombie types for each wave.
	For example, numZombieTypes[0] represents the number of zombie types in the first wave,
	and numZombieTypes[1] represents the number of zombie types in the second wave, and so on.*/

	const int zombieTypes[numWaves][4] = { {3}, {2, 3} };
	/*This is a 2D array where each row represents the zombie types for a particular wave.
	For example, zombieTypes[0] contains the zombie types for the first wave,
	and zombieTypes[1] contains the zombie types for the second wave, and so on.
	In this example, the first wave has only one zombie type (type 0),
	and the second wave has two zombie types (types 0 and 1).*/

	// Find the current wave
	int currentWave = 0;
	int elapsedSeconds = ElapsedTime.getElapsedTime().asSeconds();
	for (int i = 0; i < numWaves; ++i)
	{
		if (elapsedSeconds < waveDurations[i])
		{
			currentWave = i;
			break;
		}
	}

	// Spawn zombies for the current wave
	const int waveDuration = waveDurations[currentWave];
	const int numZombieType = numZombieTypes[currentWave];
	const int* zombieType = zombieTypes[currentWave];


	for (int j = 0; j < AllZombies.getMAX_ZOMBIES(); ++j)
	{
		if (ZombieSpawnRate.getElapsedTime().asSeconds() > 5)
		{
			for (int k = 0; k < numZombieType; ++k)
			{
				// Generate a random index to select a zombie type
				int randomTypeIndex = rand() % numZombieType;
				int type = zombieType[randomTypeIndex];

				// Check if a zombie of this type can be spawned in the current slot
				if (!AllZombies.getZombie(type, j).getExists())
				{
					AllZombies.getZombie(type, j).setExists(true);
					ZombieSpawnRate.restart();
					break; // Exit the inner loop after spawning one zombie
				}
			}
		}
	}
}

void Level1State::renderPlantFactory(sf::RenderWindow& window)
{

	int shooterPlantTypes = 4;

	int normalPlantTypes = 3;
	for (int type = 0; type < normalPlantTypes; type++)
	{
		for (int i = 0; i < 50; i++) // all plants
		{
			if (AllPlants.getNormalPlant(type, i).exists()) // check if exists then draw plant
			{
				window.draw(AllPlants.getNormalPlant(type, i).getPlantSprite());
			}
		}
	}

	for (int k = 0; k < shooterPlantTypes; k++)
	{
		for (int i = 0; i < 50; i++) // each plants could have 50 instances
		{
			if (AllPlants.getShooter(k, i).exists()) // check if exists then draw plant
			{
				window.draw(AllPlants.getShooter(k, i).getPlantSprite());
			}
			for (int j = 0; j < AllPlants.getShooter(k, i).getMaxBullets(); j++)
			{
				AllPlants.getShooter(k, i).getBullet(j).drawBullet(window); // already checking existence
			}
		}
	}

}

void Level1State::renderZombies(sf::RenderWindow& window, float deltaTime)
{
	for (int i = 0; i < 5; i++) // Loop over zombie types
	{
		for (int j = 0; j < AllZombies.getMAX_ZOMBIES(); j++) // Loop over zombies of each type
		{
			Zombie& zombie = AllZombies.getZombie(i, j);
			if (zombie.getExists()) // Check if zombie exists
			{
				// Move the zombie and set animation
				zombie.moveZombie(deltaTime);
				zombie.setAnimation();

				// Draw the zombie
				window.draw(zombie.getZombieSprite());

				// Check if this is a DancingZombie
				if (i == 3)
				{
					// Logic for Spawning backup zombies
					// Check if it's time to spawn backup zombies
					if (zombie.numBackupZombiesSpawned < 3)
					{
						// Check if backup zombies are already spawned for this DancingZombie
						if (zombie.moveClock.getElapsedTime().asSeconds() > 8)
						{
							// Loop over all zombies to find suitable slots for backup zombies
							for (int k = 0; k < AllZombies.getMAX_ZOMBIES(); k++)
							{
								// Check if backup zombie slot is available
								if (!AllZombies.getZombie(4, k).getExists())
								{
									// Spawn backup zombie
									AllZombies.getZombie(4, k).setExists(true);
									cout << "Backup zombie spawned for DancingZombie " << j << endl;

									// Set position for backup zombie based on numBackupZombiesSpawned
									float offsetX = 100.0f; // Distance between DancingZombie and BackupZombie
									float offsetY = 150.0f; // Distance between BackupZombies
									switch (zombie.numBackupZombiesSpawned)
									{
									case 0: // First BackupZombie
										AllZombies.getZombie(4, k).setx_pos(zombie.getx_pos() - offsetX);
										AllZombies.getZombie(4, k).sety_pos(zombie.gety_pos());
										break;
									case 1: // Second BackupZombie
										AllZombies.getZombie(4, k).setx_pos(zombie.getx_pos());
										AllZombies.getZombie(4, k).sety_pos(zombie.gety_pos() - offsetY);
										break;
									case 2: // Third BackupZombie
										AllZombies.getZombie(4, k).setx_pos(zombie.getx_pos() + offsetX + 20);
										AllZombies.getZombie(4, k).sety_pos(zombie.gety_pos());
										break;
									default:
										break;
									}

									// Increment counter for backup zombies spawned for this DancingZombie
									zombie.numBackupZombiesSpawned++;

									// Reset the timer for this DancingZombie
									if (zombie.numBackupZombiesSpawned == 3)
									{
										for (int m = 0; m < 50; m++)
										{
											AllZombies.getZombie(3, m).moveClock.restart();
										}
									}

									// Exit the loop to spawn only one backup zombie per DancingZombie
									break;
								}
							}
						}
					}
				}
			}
		}
	}
}

void Level1State::renderUI(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_lawnmowers; i++) // drawing lawnmower
	{
		window.draw(lawnmowers[i].getLawnMowerSprite());
	}


	window.draw(seedPacketSprite);  // Draw the seed packet (Buttons)
	window.draw(sunsNumText);
	window.draw(elapsedTimeText);
}

void Level1State::generateSuns(sf::RenderWindow& window, float deltaTime)
{
	for (int i = 0; i < 5; i++)
	{
		if ((suns[i].getExists()) == false && (sunClock.getElapsedTime().asSeconds() > 10))
		{
			sunClock.restart();
			suns[i].setExists(true);
		}
		if (suns[i].getExists() == true) // if sun exists
		{
			window.draw(suns[i].getSunSprite());
			suns[i].move(deltaTime);
		}
	}

	for (int i = 0; i < sunflowerInstances; i++) // drawing sun according to the instances of sunflower created
	{
		if (AllPlants.getNormalPlant(0, i).getSun()->getExists())
		{
			AllPlants.getNormalPlant(0, i).drawSun(window, sunsNum, sungen_Sound); // drawing sun
			sunsNumText.setString(std::to_string(sunsNum));
		}

	}

}

void Level1State::handleSunCollection(sf::RenderWindow& window)
{
	static bool LastFuncCallInput = false;
	bool currentLeftMouseButtonState = sf::Mouse::isButtonPressed(sf::Mouse::Left);
	if (currentLeftMouseButtonState && !LastFuncCallInput)
	{
		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

		for (int i = 0; i < 5; i++)
		{
			if (mousePosition.x >= suns[i].getSunSprite().getPosition().x && mousePosition.x <= (suns[i].getSunSprite().getPosition().x + (250 * 0.375)) && mousePosition.y >= suns[i].getSunSprite().getPosition().y && mousePosition.y <= (suns[i].getSunSprite().getPosition().y + (250 * 0.375)))
			{
				sungen_Sound.play();
				suns[i].setExists(false);
				suns[i].resetPosition();
				sunsNum += 50; // increment suns

				sunsNumText.setString(std::to_string(sunsNum));
				break;
			}
		}
	}
	LastFuncCallInput = currentLeftMouseButtonState;
}

void Level1State::handlePlantRemoval(sf::RenderWindow& window)
{

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		int gridX = 0;
		int gridY = 0;
		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);


		if (mousePosition.x >= 1165 && mousePosition.x <= 1252 && mousePosition.y >= 600 && mousePosition.y <= 700) // if shovel button clicked
		{
			clickedShovel = true;
		}

		gridX = (mousePosition.x / 100.66) - 3;
		gridY = (mousePosition.y / 114) - 1;

		if (clickedShovel && mousePosition.x >= 305 && mousePosition.x < 1175 && mousePosition.y >= 125 && mousePosition.y < 660 && FIELD_GAME_STATUS[gridY][gridX]) // if a place on the grid is clicked
		{

			placingPlantSound.play();

			for (int k = 0; k < 3; k++)  // 3 plant types
			{
				for (int i = 0; i < totalNormalPlantInstancesCreated; i++)
				{
					if (AllPlants.getNormalPlant(k, i).getXgridCoordinate() == gridX && AllPlants.getNormalPlant(k, i).getYgridCoordinate() == gridY)
					{
						AllPlants.getNormalPlant(k, i).setExists(false);
						FIELD_GAME_STATUS[gridY][gridX] = false;
					}
				}

			}
			for (int k = 0; k < 4; k++) // 4 shooter tyoes
			{
				for (int i = 0; i < totalShooterInstancesCreated; i++)
				{
					if (AllPlants.getShooter(k, i).getXgridCoordinate() == gridX && AllPlants.getShooter(k, i).getYgridCoordinate() == gridY)
					{
						AllPlants.getShooter(k, i).setExists(false);
						FIELD_GAME_STATUS[gridY][gridX] = false;
					}
				}
			}
			clickedShovel = false;

		}
	}
}

void Level1State::handleBulletZombieCollision(sf::RenderWindow& window)
{
	for (int i = 0; i < 4; ++i) // Iterate over shooter types
	{
		for (int j = 0; j < totalShooterInstancesCreated; ++j) // Iterate over shooter instances
		{
			Shooter& currentShooter = AllPlants.getShooter(i, j);

			for (int k = 0; k < currentShooter.getMaxBullets(); ++k) // Iterate over bullets
			{
				Bullet& currentBullet = currentShooter.getBullet(k);

				if (currentBullet.getExists()) // Check if the bullet exists
				{
					for (int l = 0; l < AllZombies.getMAX_ZOMBIES(); ++l) // Iterate over zombies
					{
						for (int m = 0; m < 5; ++m) // Iterate over zombie types
						{
							Zombie& currentZombie = AllZombies.getZombie(m, l);

							if (currentZombie.getExists())  // If that zombie exists
							{
								if (currentBullet.isColliding(currentZombie)) // Check collision
								{
									currentBullet.damageZombie(currentZombie);
									break; // No need to check other zombies
								}
							}
						}
					}
				}
			}
		}
	}
}

void Level1State::handleLawnMowerCollision(float deltaTime)
{
	for (int i = 0; i < AllZombieTypes; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			for (int k = 0; k < MAX_lawnmowers; k++)
			{
				if (lawnmowers[k].ZombieCollided(AllZombies.getZombie(i, j)))
				{
					// while(lawnmowers[k].getX_pos() < 1350)
					(lawnmowers[k].moveLawnMower(AllZombies.getZombie(i, j), deltaTime));//  moving the lawnmower
				}
			}
		}
	}
}


void Level1State::Init(AssetManager& Assets)
{
	background.setTexture(Assets.getTexture(26));
	setPlantFactoryTextures(Assets);
	setZombieTextures(Assets);
	setUITextures(Assets);
}
void Level1State::HandleInput(StateMachine* machine, sf::RenderWindow& window)
{
	handleAllPlantsCreation(window);
	handleSunCollection(window);
	handlePlantRemoval(window);

	handleBulletZombieCollision(window); // handle collisions between bullet and zombie


	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

		if (mousePosition.x >= 1165 && mousePosition.x <= 1252 && mousePosition.y >= 31 && mousePosition.y <= 112)
		{
			machine->AddState(StateRef(new PauseGameState(26)), false);  // Switching to the Pause game state
		}
	}
}
void Level1State::Update(StateMachine* machine, float deltaTime)
{
	int shooterPlanttypes = 4;
	// For plant factory
	for (int k = 0; k < shooterPlanttypes; k++)
	{
		for (int i = 0; i < totalShooterInstancesCreated; i++)
		{
			AllPlants.getShooter(k, i).Act();
			AllPlants.getShooter(k, i).shootBullet(deltaTime);
		}
	}

	int normalPlantTypes = 3;
	for (int k = 0; k < normalPlantTypes; k++)
	{
		for (int i = 0; i < totalNormalPlantInstancesCreated; i++)
		{
			AllPlants.getNormalPlant(k, i).Act();
		}
	}

	Level1State::spawnZombies();
	Level1State::handleLawnMowerCollision(deltaTime);



	// DISPLAYING THE ELAPSED TIME
	int minutes = static_cast<int>(ElapsedTime.getElapsedTime().asSeconds()) / 60;
	int seconds = static_cast<int>(ElapsedTime.getElapsedTime().asSeconds()) % 60;

	// Update the text to display the elapsed time
	std::string timeString = "Time: ";
	if (minutes < 10)
		timeString += "0";
	timeString += std::to_string(minutes) + ":";
	if (seconds < 10)
		timeString += "0";

	timeString += std::to_string(seconds);
	elapsedTimeText.setString(timeString);
}
void Level1State::Draw(sf::RenderWindow& window, float deltaTime)
{
	window.draw(background);
	renderPlantFactory(window);
	renderZombies(window, deltaTime);  // This also handles the movement of zombies
	renderUI(window);
	generateSuns(window, deltaTime);  // This also handles the movement of suns
	window.display();
	window.clear();
}