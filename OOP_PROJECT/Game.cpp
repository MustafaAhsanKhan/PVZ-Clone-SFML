#include "Game.h"

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
    Assets.loadTexture(0, "../PVZ_Textures/backgrounds/level2.png");
    Assets.loadTexture(20, "../PVZ_Textures/Seed_Packets_Transparent.png");
    Assets.loadTexture(21, "../PVZ_Textures/Lawn_Mower2.png");

    sf::IntRect textureRect(0, 73, 143, 550);

    // Seed packet sprite
    seedPacketSprite.setTexture(Assets.getTexture(20));
    seedPacketSprite.setTextureRect(textureRect);
    seedPacketSprite.setPosition(50, 70);

    // Lawn mower sprite
    for (int i = 0; i < 5; i++)
    {
		lawnMowerSprite[i].setTexture(Assets.getTexture(21));
		lawnMowerSprite[i].setPosition(185, (i * 118) + 70);
	}

    mapSprite.setTexture(Assets.getTexture(0));
}

void Game::InitializePlantTextures()
{
    Assets.loadTexture(1, "../PVZ_Textures/PlantTextures/Peashooter.png");  // Plant texture
    Assets.loadTexture(2, "../PVZ_Textures/PlantTextures/Repeater.png");
    Assets.loadTexture(3, "../PVZ_Textures/PlantTextures/SnowPea.png");
    Assets.loadTexture(4, "../PVZ_Textures/PlantTextures/Peashooter.png");  // Bullet texture
    Assets.loadTexture(5, "../PVZ_Textures/PlantTextures/Sunflower.png");
    Assets.loadTexture(6, "../PVZ_Textures/PlantTextures/Cherrybomb.png");
    Assets.loadTexture(7, "../PVZ_Textures/PlantTextures/Wallnut.png");
}

void Game::InitializeZombieTextures()
{
	Assets.loadTexture(10, "../PVZ_Textures/Zombies/simple_zombie.png");
    Assets.loadTexture(11, "../PVZ_Textures/Zombies/flying_zombie.png");
    Assets.loadTexture(12, "../PVZ_Textures/Zombies/football_zombie.png");
    Assets.loadTexture(13, "../PVZ_Textures/Zombies/dancing_zombie.png");
    Assets.loadTexture(14, "../PVZ_Textures/Zombies/dolphin_rider_zombie.png");
}


void Game::setPlantFactoryTextures()
{
    textureRect = sf::IntRect(0, 0, 27.125, 31);  // Peashooter
    for (int i = 0; i < 50; i++) // 50 plants
    {
        AllPlants.getShooter(0, i).getPlantSprite().setTexture(Assets.getTexture(1));
        AllPlants.getShooter(0, i).getPlantSprite().setTextureRect(textureRect);
        AllPlants.getShooter(0, i).getPlantSprite().setScale(3, 3);

    }

    // the Shooter's bullets
    textureRect = sf::IntRect(78, 38, 10, 20);
    for (int i = 0; i < 50; i++) // 50 plants
    {
        for (int j = 0; j < AllPlants.getShooter(0, i).getMaxBullets(); j++)
        {
            AllPlants.getShooter(0, i).getBullet(j).getBulletSprite().setTexture(Assets.getTexture(4));
            AllPlants.getShooter(0, i).getBullet(j).getBulletSprite().setScale(3, 3);
            AllPlants.getShooter(0, i).getBullet(j).getBulletSprite().setTextureRect(textureRect);
        }

    }

}

void Game::setZombieTextures()
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



void Game::handleAllPlantsCreation()
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        int gridX = 0;
        int gridY = 0;


        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

        gridX = (mousePosition.x / 100.66) - 3;
        gridY = (mousePosition.y / 114) - 1;

        const int totalplanttypes = 1; // will be 6 once all are implemented
        const int eachtypenum = 5; // total types
        // int totaltypescreated = 1; // the total instances of each type currently
        int plantscreated = 1; // currently

            // checks if seed packet clicked
            if (mousePosition.x > 52 && mousePosition.x <= 191 && mousePosition.y >= 55 && mousePosition.y <= 144)
            {
                clickedSeedPacket[0] = true;
            }
            if (mousePosition.x > 52 && mousePosition.x <= 191 && mousePosition.y >= 144 && mousePosition.y <= 233)
            {
                if (!clickedSeedPacket[0])
                {
                    clickedSeedPacket[1] = true;
                }
                
            }
            for (int i = 0; i < totalplanttypes; i++)
            {
            
                 if (mousePosition.x >= 305 && mousePosition.x < 1175 && mousePosition.y >= 125 && mousePosition.y < 660 && clickedSeedPacket[1] == true && FIELD_GAME_STATUS[gridY][gridX] == false)
                 {
                     AllPlants.getShooter(totalplanttypes - 1, totaltypescreated - 1).getPlantSprite().setPosition(gridX * 100.66 + 315, gridY * 114 + 115);
                     AllPlants.getShooter(totalplanttypes - 1, totaltypescreated - 1).setXgridCoordinate(gridX);
                     AllPlants.getShooter(totalplanttypes - 1, totaltypescreated - 1).setYgridCoordinate(gridY);
                     AllPlants.getShooter(totalplanttypes - 1, totaltypescreated - 1).setExists(true);
                     totaltypescreated++;
                     cout << "NEW PLANT CREATED! ";
                     FIELD_GAME_STATUS[gridY][gridX] = true;  // So another plant cant be placed on the same spot
                     clickedSeedPacket[1] = false;
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
   
    /*for (int i = 0; i < 10; i++)
    {
        AllPlants.getShooter(0, i).getPlantSprite().setPosition(-100, -100);
    }
    
    plant->getPlantSprite().setPosition(-100, -100);*/

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
        //machine.ProcessStateChanges();

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
        for (int i = 0; i < totaltypescreated; i++)
        {
            AllPlants.getShooter(0, i).setAnimation();
            AllPlants.getShooter(0, i).shootBullet(deltaTime);
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