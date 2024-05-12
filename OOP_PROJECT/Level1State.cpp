#include "Level1State.h"

Level1State::Level1State()
{
	// Sounds
	backgroundMusic.openFromFile("../Sounds/backgroundmusic.ogg");
	backgroundMusic.setVolume(5); // change later
	backgroundMusic.play();
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
	sunsNum = 0;
	font.loadFromFile("../Fonts/Wedges.ttf");
	sunsNumText.setFont(font);
	sunsNumText.setCharacterSize(40); // Set font size
	sunsNumText.setFillColor(sf::Color::White);
	sunsNumText.setPosition(107, 20);
	sunsNumText.setString(std::to_string(sunsNum));

	// shovel sprite
	clickedShovel = false;

	// Sun
	sunCount = 10;
	suns = new Sun[sunCount];

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


	// Setting random coordinates to zombies
	srand(time(0));
	for (int i = 0; i < 4; i++)  // This controls the type of zombie
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
	textureRect = sf::IntRect(78, 38, 10, 20);
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
	textureRect = sf::IntRect(90, 44.95, 23, 20);
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
	textureRect = sf::IntRect(0, 106, 32, 15);
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
	textureRect = sf::IntRect(0, 58.28, 51.11, 58.28);  // SimpleZombie
	for (int i = 0; i < AllZombies.getMAX_ZOMBIES(); i++)
	{
		AllZombies.getZombie(0, i).getZombieSprite().setTexture(Assets.getTexture(10));
		AllZombies.getZombie(0, i).getZombieSprite().setTextureRect(textureRect);
		AllZombies.getZombie(0, i).getZombieSprite().setScale(3, 3);
	}

	textureRect = sf::IntRect(0, 0, 34.95, 58);  // FlyingZombie
	for (int i = 0; i < AllZombies.getMAX_ZOMBIES(); i++)
	{
		AllZombies.getZombie(1, i).getZombieSprite().setTexture(Assets.getTexture(11));
		AllZombies.getZombie(1, i).getZombieSprite().setTextureRect(textureRect);
		AllZombies.getZombie(1, i).getZombieSprite().setScale(3, 3);
	}

	textureRect = sf::IntRect(0, 67.74, 64, 67.74);  // FootballZombie
	for (int i = 0; i < AllZombies.getMAX_ZOMBIES(); i++)
	{
		AllZombies.getZombie(2, i).getZombieSprite().setTexture(Assets.getTexture(12));
		AllZombies.getZombie(2, i).getZombieSprite().setTextureRect(textureRect);
		AllZombies.getZombie(2, i).getZombieSprite().setScale(2.5, 2.5);
	}

	textureRect = sf::IntRect(0, 80, 56, 80);  // DancingZombie
	for (int i = 0; i < AllZombies.getMAX_ZOMBIES(); i++)
	{
		AllZombies.getZombie(3, i).getZombieSprite().setTexture(Assets.getTexture(13));
		AllZombies.getZombie(3, i).getZombieSprite().setTextureRect(textureRect);
		AllZombies.getZombie(3, i).getZombieSprite().setScale(2.2, 2.2);
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
	// Lawn mower sprite
	for (int i = 0; i < 5; i++)
	{
		lawnMowerSprite[i].setTexture(Assets.getTexture(31));
		lawnMowerSprite[i].setScale(0.28, 0.28);
		lawnMowerSprite[i].setPosition(220, (i * 117.5) + 120);
	}
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
						//sunflowerSunClock.restart();
						//sunflowerSun[sunflowerInstances++].setExists(true); // sunflower Suns will generate
						//sunflowerSun[sunflowerInstances - 1].setXpos(gridX * 100.66);
						//sunflowerSun[sunflowerInstances - 1].setYpos(gridY * 114 + 150);
						//sunflowerSun[sunflowerInstances - 1].getSunSprite().setPosition(gridX * 100.66, gridY * 114 + 150);
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
						// AllPlants.getNormalPlant(1, totalNormalPlantInstancesCreated - 1).getPlantSprite().setPosition(gridX * 100.66 + 315, gridY * 114 + 110);
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
	if (ElapsedTime.getElapsedTime().asSeconds() > 5 && ElapsedTime.getElapsedTime().asSeconds() < 60)  // Wave 1
	{
		zombieWave.play(); // playing zombie sound
		for (int j = 0; j < AllZombies.getMAX_ZOMBIES(); j++)  // This controls the number of zombies
		{
			if (ZombieSpawnRate.getElapsedTime().asSeconds() > 5)  // 12 zombies spawning
			{

				if (!AllZombies.getZombie(0, j).getExists())
				{
					AllZombies.getZombie(0, j).setExists(true);  // Creating a new zombie
					ZombieSpawnRate.restart();
					break;
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
	for (int i = 0; i < 4; i++)  // This controls the type of zombie
	{
		for (int j = 0; j < AllZombies.getMAX_ZOMBIES(); j++)  // This controls the number of zombies
		{
			if (AllZombies.getZombie(i, j).getExists())
			{
				AllZombies.getZombie(i, j).moveZombie(deltaTime);
				AllZombies.getZombie(i, j).setAnimation();
				window.draw(AllZombies.getZombie(i, j).getZombieSprite());
			}
		}
	}
}

void Level1State::renderUI(sf::RenderWindow& window)
{
	for (int i = 0; i < 5; i++)
	{
		window.draw(lawnMowerSprite[i]);
	}
	window.draw(seedPacketSprite);  // Draw the seed packet (Buttons)
	window.draw(sunsNumText);
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

	spawnZombies();


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