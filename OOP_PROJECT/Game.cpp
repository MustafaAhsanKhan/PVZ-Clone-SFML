#include "Game.h"
#include<iostream>
using namespace sf;

// int Game::totaltypescreated = 1; // current plant types created

Game::Game() : window(sf::VideoMode(1280, 720), "Plants Vs Zombies", sf::Style::Titlebar | sf::Style::Close)
{
	// Initialize Plants
	isPlacingPlant = false;  // will be set to true when the user clicks on a plant to place it

	// Initialize Zombies
	zombie = NULL;  // Currently no zombies exist


	// Initialize the game grid status
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			FIELD_GAME_STATUS[i][j] = false;  // Initially all the grid is empty
		}
	}
	for (int i = 0; i < 2; i++)
	{
		clickedSeedPacket[i] = false;
	}
	// Initialize the UI
	Game::InitializeUISprites();
	float scaleX = static_cast<float>(window.getSize().x) / mapSprite.getLocalBounds().width;
	float scaleY = static_cast<float>(window.getSize().y) / mapSprite.getLocalBounds().height;
	mapSprite.setScale(scaleX, scaleY);

	// Game icon
	Image icon;
	if (!icon.loadFromFile("../PVZ_Textures/icon.png"))
	{
		return;
	}
	window.setIcon(32, 32, icon.getPixelsPtr());
	Game::InitializePlantTextures();
	Game::setPlantFactoryTextures();
	Game::InitializeZombieTextures();
	Game::setZombieTextures();
}

void Game::InitializeMusic()
{
	// backgroundMusic.openFromFile("Sounds/backgroundMusic.mp3");
	// backgroundMusic.play();
}

void Game::InitializeUISprites()
{
	Asset_Texture.loadTexture(0, "../PVZ_Textures/backgrounds/level2.png");
	Asset_Texture.loadTexture(20, "../PVZ_Textures/Seed_Packets_Sprites.png");
	Asset_Texture.loadTexture(21, "../PVZ_Textures/Lawn_Mower2.png");

	sf::IntRect textureRect(0, 45, 143, 675);

	// Seed packet sprite
	seedPacketSprite.setTexture(Asset_Texture.getTexture(20));
	seedPacketSprite.setTextureRect(textureRect);
	seedPacketSprite.setPosition(50, 70);

	// Lawn mower sprite
	for (int i = 0; i < 5; i++)
	{
		lawnMowerSprite[i].setTexture(Asset_Texture.getTexture(21));
		lawnMowerSprite[i].setPosition(185, (i * 118) + 70);
	}

	mapSprite.setTexture(Asset_Texture.getTexture(0));
}

void Game::InitializePlantTextures()
{
	Asset_Texture.loadTexture(1, "../PVZ_Textures/PlantTextures/Sunflower.png");
	Asset_Texture.loadTexture(2, "../PVZ_Textures/PlantTextures/Peashooter.png");  // Plant texture
	Asset_Texture.loadTexture(3, "../PVZ_Textures/PlantTextures/Wallnut.png");
	Asset_Texture.loadTexture(4, "../PVZ_Textures/PlantTextures/Peashooter.png");  // Bullet texture
	Asset_Texture.loadTexture(5, "../PVZ_Textures/PlantTextures/SnowPea.png"); // snow pea bullet texture
	Asset_Texture.loadTexture(6, "../PVZ_Textures/PlantTextures/SnowPea.png");
	Asset_Texture.loadTexture(7, "../PVZ_Textures/PlantTextures/Cherrybomb.png");
	Asset_Texture.loadTexture(8, "../PVZ_Textures/PlantTextures/Repeater.png");
}

void Game::InitializeZombieTextures()
{
	Asset_Texture.loadTexture(10, "../PVZ_Textures/Zombies/simple_zombie.png");
	Asset_Texture.loadTexture(11, "../PVZ_Textures/Zombies/flying_zombie.png");
	Asset_Texture.loadTexture(12, "../PVZ_Textures/Zombies/football_zombie.png");
	Asset_Texture.loadTexture(13, "../PVZ_Textures/Zombies/dancing_zombie.png");
	Asset_Texture.loadTexture(14, "../PVZ_Textures/Zombies/dolphin_rider_zombie.png");
}


void Game::setPlantFactoryTextures()
{
	textureRect = sf::IntRect(0, 0, 27.125, 31);  // initially wokrs for normal peashooter
	int totalShooterTypes = 2;


	// TEXTURE SETTING PART CAN BE HARDCODED THERES NO PROBLEM

	for (int i = 0; i < 50; i++) // 50 plants
	{
		AllPlants.getShooter(0, i).getPlantSprite().setTexture(Asset_Texture.getTexture(2));
		AllPlants.getShooter(0, i).getPlantSprite().setTextureRect(textureRect);
		AllPlants.getShooter(0, i).getPlantSprite().setScale(3, 3);
	}
	// ADD FOR OTHER SHOOTERS


	// THE SHOOTERS BULLETS
	textureRect = sf::IntRect(78, 38, 10, 20); // initially wokrs for normal peashooter
	int bullettextureindex = 4;


	for (int i = 0; i < 50; i++) // 50 plants
	{
		for (int j = 0; j < AllPlants.getShooter(0, i).getMaxBullets(); j++)
		{
			AllPlants.getShooter(0, i).getBullet(j).getBulletSprite().setTexture(Asset_Texture.getTexture(bullettextureindex));
			AllPlants.getShooter(0, i).getBullet(j).getBulletSprite().setScale(3, 3);
			AllPlants.getShooter(0, i).getBullet(j).getBulletSprite().setTextureRect(textureRect);
		}
	}

	// TEXTURE SETTING PART CAN BE HARDCODED THERES NO PROBLEM
	textureRect = sf::IntRect(101.9, 36.75, 30, 32); // sunflower
	for (int i = 0; i < 50; i++) // 50 plants
	{
		AllPlants.getNormalPlant(0, i).getPlantSprite().setTexture(Asset_Texture.getTexture(1));
		AllPlants.getNormalPlant(0, i).getPlantSprite().setTextureRect(textureRect);
		AllPlants.getNormalPlant(0, i).getPlantSprite().setScale(3, 3);
	}




}

void Game::setZombieTextures()
{
	zombie = &SimpleZombie;

	textureRect = sf::IntRect(0, 58.28, 51.11, 58.28);

	zombie->getZombieSprite().setTexture(Asset_Texture.getTexture(10));
	zombie->getZombieSprite().setScale(3, 3);

	zombie->getZombieSprite().setTextureRect(textureRect);

	zombie = &FlyingZombie;

	textureRect = sf::IntRect(0, 0, 34.95, 58);
	zombie->getZombieSprite().setTexture(Asset_Texture.getTexture(11));
	zombie->getZombieSprite().setScale(3, 3);

	zombie->getZombieSprite().setTextureRect(textureRect);

	zombie = &FootballZombie;
	textureRect = sf::IntRect(0, 67.74, 64, 67.74);
	zombie->getZombieSprite().setTexture(Asset_Texture.getTexture(12));
	zombie->getZombieSprite().setScale(2.5, 2.5);
	zombie->getZombieSprite().setTextureRect(textureRect);

	zombie = &DancingZombie;
	textureRect = sf::IntRect(0, 80, 56, 80);
	zombie->getZombieSprite().setTexture(Asset_Texture.getTexture(13));
	zombie->getZombieSprite().setScale(2.2, 2.2);
	zombie->getZombieSprite().setTextureRect(textureRect);
}



void Game::handleAllPlantsCreation()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		int gridX = 0;
		int gridY = 0;


		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

		gridX = (mousePosition.x / 100.66) - 3;
		gridY = (mousePosition.y / 114) - 1;

		const int totalPlantTypes = 4; // will be 6 once all are implemented
		const int eachtypenum = 5; // total types
		// int totaltypescreated = 1; // the total instances of each type currently
		int plantscreated = 1; // currently
		int plantTypescreated = 1;
		int seedPacketnum = 3;

		/*
		FOR CLARITY:
		clickedSeedPacket[]
		sunflower index : 0
		peashooter index : 1
		Wallnut index: 2

		Texture indexes:
		sunflower index : 1
		peashooter index : 2
		Wallnut index: 3
		*/




		// checks if seed packet clicked
		for (int i = 0; i < totalPlantTypes; ++i)
		{
			if (mousePosition.x > 52 && mousePosition.x <= 191 && mousePosition.y >= (55 + 89 * i + 1) && mousePosition.y <= (144 + 89 * i + 1))
			{
				for (int j = 0; j < totalPlantTypes; j++)
				{
					clickedSeedPacket[j] = false;
				}

				clickedSeedPacket[i] = true;
				break; // Exit loop once the clicked seed packet is found
			}
		}
		
		for (int i = 0; i < totalPlantTypes; i++)
		{

			if (mousePosition.x >= 305 && mousePosition.x < 1175 && mousePosition.y >= 125 && mousePosition.y < 660 && clickedSeedPacket[i] == true && FIELD_GAME_STATUS[gridY][gridX] == false)
			{
				switch (i)
				{
				case 0:
				{
					AllPlants.getNormalPlant(0, totalTypeInstancesCreated - 1).getPlantSprite().setPosition(gridX * 100.66 + 315, gridY * 114 + 115);
					AllPlants.getNormalPlant(0, totalTypeInstancesCreated - 1).setXgridCoordinate(gridX);
					AllPlants.getNormalPlant(0, totalTypeInstancesCreated - 1).setYgridCoordinate(gridY);
					AllPlants.getNormalPlant(0, totalTypeInstancesCreated - 1).setExists(true);
					totalTypeInstancesCreated++;
					cout << "Sunflower created\n";
					FIELD_GAME_STATUS[gridY][gridX] = true;  // So another plant cant be placed on the same spot
					clickedSeedPacket[i] = false;
					break;
					
				}
					
				case 1:
				{
					AllPlants.getShooter(0, totalTypeInstancesCreated - 1).getPlantSprite().setPosition(gridX * 100.66 + 315, gridY * 114 + 115);
					AllPlants.getShooter(0, totalTypeInstancesCreated - 1).setXgridCoordinate(gridX);
					AllPlants.getShooter(0, totalTypeInstancesCreated - 1).setYgridCoordinate(gridY);
					AllPlants.getShooter(0, totalTypeInstancesCreated - 1).setExists(true);
					totalTypeInstancesCreated++;
					cout << "Peashooter created\n";
					FIELD_GAME_STATUS[gridY][gridX] = true;  // So another plant cant be placed on the same spot
					clickedSeedPacket[i] = false;
					break;
				}
					
				case 2:
				{
					AllPlants.getNormalPlant(0, totalTypeInstancesCreated - 1).getPlantSprite().setPosition(gridX * 100.66 + 315, gridY * 114 + 115);
					AllPlants.getNormalPlant(0, totalTypeInstancesCreated - 1).setXgridCoordinate(gridX);
					AllPlants.getNormalPlant(0, totalTypeInstancesCreated - 1).setYgridCoordinate(gridY);
					AllPlants.getNormalPlant(0, totalTypeInstancesCreated - 1).setExists(true);
					totalTypeInstancesCreated++;
					cout << "Sunflower created\n";
					FIELD_GAME_STATUS[gridY][gridX] = true;  // So another plant cant be placed on the same spot
					clickedSeedPacket[i] = false;
					break;
				}

				}
				break;
			}

		}
	}
}

void Game::renderPlantFactory()
{

	for (int i = 0; i < 50; i++) // all plants 
	{
		if (AllPlants.getShooter(0, i).exists()) // check if exists then draw plant
		{
			window.draw(AllPlants.getShooter(0, i).getPlantSprite());
		}
		for (int j = 0; j < AllPlants.getShooter(0, i).getMaxBullets(); j++)
		{
			AllPlants.getShooter(0, i).getBullet(j).drawBullet(window); // already checking existence
		}
	}
	for (int i = 0; i < 50; i++) // all plants 
	{
		if (AllPlants.getNormalPlant(0, i).exists()) // check if exists then draw plant
		{
			window.draw(AllPlants.getNormalPlant(0, i).getPlantSprite());
		}
	}



}

void Game::renderZombies()
{
	window.draw(zombie->getZombieSprite());
}

void Game::renderUI()
{
	window.draw(mapSprite);
	for (int i = 0; i < 5; i++)
	{
		window.draw(lawnMowerSprite[i]);
	}
	window.draw(seedPacketSprite);  // Draw the seed packet (Buttons)
}


void Game::run()
{
	srand(time(0));

	Clock zombieClock;
	float deltaTime = 0.0;
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

	while (window.isOpen())
	{
		deltaClock.restart();
		deltaTime = deltaClock.getElapsedTime().asSeconds();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		Game::InitializeMusic();

		Game::renderUI(); // render the UI

		Game::handleAllPlantsCreation();

		// For plant factory
		for (int i = 0; i < totalTypeInstancesCreated; i++)
		{
			AllPlants.getShooter(0, i).setAnimation();
			AllPlants.getShooter(0, i).shootBullet(deltaTime);
		}
		for (int i = 0; i < totalTypeInstancesCreated; i++)
		{
			AllPlants.getNormalPlant(0, i).setAnimation();
		}
		

		Game::renderPlantFactory();

		if (zombie != nullptr)
		{
			zombie = &FlyingZombie;
			zombie->moveZombie(deltaTime);
			zombie->setAnimation();
			Game::renderZombies();

			zombie = &SimpleZombie;
			zombie->moveZombie(deltaTime);
			zombie->setAnimation();
			Game::renderZombies();

			zombie = &FootballZombie;
			zombie->moveZombie(deltaTime);
			zombie->setAnimation();
			Game::renderZombies();

			zombie = &DancingZombie;
			zombie->moveZombie(deltaTime);
			zombie->setAnimation();
			Game::renderZombies();
		}


		window.display();
		window.clear();
	}
}