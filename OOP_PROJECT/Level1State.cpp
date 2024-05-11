#include "Level1State.h"

Level1State::Level1State()
{
	// Sounds
	sungen_SoundBuffer.loadFromFile("../Sounds/plants-vs-zombies-sun-pickup.ogg");
	sungen_Sound.setBuffer(sungen_SoundBuffer);
	sungen_Sound.setVolume(15);
	placingPlantSoundBuffer.loadFromFile("../Sounds/plantplacingsound.ogg");
	placingPlantSound.setBuffer(placingPlantSoundBuffer);
	placingPlantSound.setVolume(15);

	// Fonts
	sunsNum = 5000;
	font.loadFromFile("../Fonts/Wedges.ttf");
	sunsNumText.setFont(font);
	sunsNumText.setCharacterSize(40); // Set font size
	sunsNumText.setFillColor(sf::Color::White);
	sunsNumText.setPosition(107, 20);
	sunsNumText.setString(std::to_string(sunsNum));

	// shovel sprite
	clickedShovel = false;

	// Sun
	sunCount = 5;
	currentSuns = 0;
	suns = new Sun[sunCount];


	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			FIELD_GAME_STATUS[i][j] = false;  // Initially all the grid is empty
		}
	}

	for (int i = 0; i < 7; i++)
	{
		clickedSeedPacket[i] = false;
	}

	int temp = rand() % 5;

	zombie = &SimpleZombie;
	zombie->setXgridCoordinate(8);
	zombie->setYgridCoordinate(temp);
	zombie->setx_pos(1180);
	zombie->sety_pos((120 * temp) + 40);


	temp = rand() % 5;
	zombie = &FlyingZombie;

	zombie->setXgridCoordinate(8);
	zombie->setYgridCoordinate(temp);
	zombie->setx_pos(1180);
	zombie->sety_pos((120 * temp) + 40);

	temp = rand() % 5;
	zombie = &FootballZombie;

	zombie->setXgridCoordinate(8);
	zombie->setYgridCoordinate(temp);
	zombie->setx_pos(1180);
	zombie->sety_pos((120 * temp) + 40);

	temp = rand() % 5;
	zombie = &DancingZombie;

	zombie->setXgridCoordinate(8);
	zombie->setYgridCoordinate(temp);
	zombie->setx_pos(1180);
	zombie->sety_pos((120 * temp) + 40);

	temp = rand() % 5;
	zombie = &DolphinRiderZombie;

	zombie->setXgridCoordinate(8);
	zombie->setYgridCoordinate(temp);
	zombie->setx_pos(1180);
	zombie->sety_pos((120 * temp) + 40);
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
			for (int j = 0; j < AllPlants.getShooter(0, i).getMaxBullets(); j++)
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
	zombie = &SimpleZombie;

	textureRect = sf::IntRect(0, 58.28, 51.11, 58.28);

	zombie->getZombieSprite().setTexture(Assets.getTexture(10));
	zombie->getZombieSprite().setScale(3, 3);

	zombie->getZombieSprite().setTextureRect(textureRect);

	zombie = &FlyingZombie;

	textureRect = sf::IntRect(0, 0, 34.95, 58);
	zombie->getZombieSprite().setTexture(Assets.getTexture(11));
	zombie->getZombieSprite().setScale(3, 3);

	zombie->getZombieSprite().setTextureRect(textureRect);

	zombie = &FootballZombie;
	textureRect = sf::IntRect(0, 67.74, 64, 67.74);
	zombie->getZombieSprite().setTexture(Assets.getTexture(12));
	zombie->getZombieSprite().setScale(2.5, 2.5);
	zombie->getZombieSprite().setTextureRect(textureRect);

	zombie = &DancingZombie;
	textureRect = sf::IntRect(0, 80, 56, 80);
	zombie->getZombieSprite().setTexture(Assets.getTexture(13));
	zombie->getZombieSprite().setScale(2.2, 2.2);
	zombie->getZombieSprite().setTextureRect(textureRect);
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

		const int totalPlantTypes = 7; // will be 6 once all are implemented
		const int eachtypenum = 5; // total types
		// int totalTypeInstancesCreated = 1; // the total instances of each type currently
		int plantscreated = 1; // currently
		int plantTypescreated = 1;
		int seedPacketnum = 3;

		/*
		FOR CLARITY:
		1. clickedSeedPacket[]
		sunflower index : 0
		peashooter index : 1
		Wallnut index: 2
		Cherrybomb index: 3
		Repeater index: 4
		Snow Pea index: 5
		Fumeshroom index: 6

		2. Texture indexes:
		sunflower index : 1
		peashooter index : 2
		Wallnut index: 3
		Cherrybomb index: 4
		Repeater index: 5
		Snow Pea index: 6
		Fumeshroom index: 7
		*/

		// checks if seed packet clicked
		for (int i = 0; i < totalPlantTypes; ++i)
		{
			cout << mousePosition.x << " " << mousePosition.y << endl;

			if (mousePosition.x > 52 && mousePosition.x <= 150 && mousePosition.y >= (112 + 75 * i + 1) && mousePosition.y <= (230 + 75 * i + 1))
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
				{
					if (sunsNum >= 100)
					{
						sunsNum -= 100;
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
				}

				case 1:
				{
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

				}

				case 2:
				{
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

				}
				case 3:
				{
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

				}
				case 4:
				{
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

				}
				case 5:
				{
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

				}
				case 6:
				{
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
}

void Level1State::renderPlantFactory(sf::RenderWindow& window)
{

	int shooterPlantTypes = 4;
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


}

void Level1State::renderZombies(sf::RenderWindow& window)
{
	zombie = &FlyingZombie;
	window.draw(zombie->getZombieSprite());

	zombie = &SimpleZombie;
	window.draw(zombie->getZombieSprite());

	zombie = &FootballZombie;
	window.draw(zombie->getZombieSprite());

	zombie = &DancingZombie;
	window.draw(zombie->getZombieSprite());

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

void Level1State::generateSuns(sf::RenderWindow& window)
{
	for (int i = 0; i < 5; i++)
	{
		if ((suns[i].getExists()) == false && (sunClock.getElapsedTime().asSeconds() > 10))
		{
			sunClock.restart();
			suns[i].setExists(true);
			sungen_Sound.play();
		}
		if (suns[i].getExists() == true)
		{
			window.draw(suns[i].getSunSprite());
			suns[i].move();

		}
	}

}

void Level1State::handleSunCollection(sf::RenderWindow& window)
{
	static bool LastFuncCallInput = false;
	bool currentLeftMouseButtonState = sf::Mouse::isButtonPressed(sf::Mouse::Left);
	if (currentLeftMouseButtonState && !LastFuncCallInput) {
		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

		for (int i = 0; i < 5; i++) {
			if (mousePosition.x >= suns[i].getSunSprite().getPosition().x && mousePosition.x <= (suns[i].getSunSprite().getPosition().x + (250 * 0.375)) && mousePosition.y >= suns[i].getSunSprite().getPosition().y && mousePosition.y <= (suns[i].getSunSprite().getPosition().y + (250 * 0.375)))
			{

				suns[i].resetPosition();
				suns[i].setExists(false);
				sunsNum += 50;
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

	if (zombie != nullptr)
	{
		zombie = &FlyingZombie;
		zombie->moveZombie(deltaTime);
		zombie->setAnimation();

		zombie = &SimpleZombie;
		zombie->moveZombie(deltaTime);
		zombie->setAnimation();

		zombie = &FootballZombie;
		zombie->moveZombie(deltaTime);
		zombie->setAnimation();

		zombie = &DancingZombie;
		zombie->moveZombie(deltaTime);
		zombie->setAnimation();
	}
}
void Level1State::Draw(sf::RenderWindow& window)
{
	window.draw(background);
	renderPlantFactory(window);
	renderZombies(window);
	renderUI(window);
	generateSuns(window);
	window.display();
	window.clear();
}