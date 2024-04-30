#include "Game.h"
#include<iostream>
using namespace sf;

Game::Game() : window(sf::VideoMode(1280, 720), "Plants Vs Zombies", sf::Style::Titlebar | sf::Style::Close)
{
    // Initialize Plants
    //plant = new Plant; // will handle the plants array later
    //shooters = new PeaShooter;
    plant = NULL;  // Currently no plants exist
    shooters = NULL;
    isPlacingPlant = false;  // will be set to true when the user clicks on a plant to place it

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
        clickedseedPacket[i] = false;
    }
    // Initialize the UI
    InitializeUISprites();
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
    
    InitializePlantTextures();
    setPlantTextures();
    
}

void Game::InitializeUISprites()
{
    Asset_Texture.loadTexture(0, "../PVZ_Textures/backgrounds/level2.png");
    Asset_Texture.loadTexture(20, "../PVZ_Textures/Seed_Packets.png");
    Asset_Texture.loadTexture(21, "../PVZ_Textures/Lawn_Mower2.png");

    sf::IntRect textureRect(0, 73, 143, 550);

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
    Asset_Texture.loadTexture(1, "../PVZ_Textures/PlantTextures/Peashooter.png");  // Plant texture
    Asset_Texture.loadTexture(2, "../PVZ_Textures/PlantTextures/Repeater.png");
    Asset_Texture.loadTexture(3, "../PVZ_Textures/PlantTextures/SnowPea.png");
    Asset_Texture.loadTexture(4, "../PVZ_Textures/PlantTextures/Peashooter.png");  // Bullet texture
    Asset_Texture.loadTexture(5, "../PVZ_Textures/PlantTextures/Sunflower.png");
    Asset_Texture.loadTexture(6, "../PVZ_Textures/PlantTextures/Cherrybomb.png");
    Asset_Texture.loadTexture(7, "../PVZ_Textures/PlantTextures/Wallnut.png");
}

void Game::InitializeZombieTextures()
{
	Asset_Texture.loadTexture(8, "../PVZ_Textures/Zombies/simple_zombie.png");
    Asset_Texture.loadTexture(9, "../PVZ_Textures/Zombies/flying_zombie.png");
    Asset_Texture.loadTexture(10, "../PVZ_Textures/Zombies/football_zombie.png");
    Asset_Texture.loadTexture(11, "../PVZ_Textures/Zombies/dancing_zombie.png");
    Asset_Texture.loadTexture(12, "../PVZ_Textures/Zombies/dolphin_rider_zombie.png");
}


void Game::handlePlantCreation()
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        int gridX = 0;
        int gridY = 0;


        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

        gridX = (mousePosition.x / 100.66);
        gridY = (mousePosition.y / 114);

        int totalplanttypes = 1;
        int eachtypenum = 5;
        int totaltypescreated = 1;
        // for peashooter
        int plantscreated = 1;
        for (int i = 0; i < totalplanttypes; i++)
        {
            for (int j = 0; i < eachtypenum; i++)
            {               
                // for sunflower
                if (mousePosition.x > 52 && mousePosition.x <= 191 && mousePosition.y >= 55 && mousePosition.y <= 144)
                {
                    clickedseedPacket[0] = true;
                }

                // for peashooter
                if (mousePosition.x > 52 && mousePosition.x <= 191 && mousePosition.y >= 144 && mousePosition.y <= 233)
                {
                    clickedseedPacket[1] = true;
                }
                
                if (mousePosition.x >= 305 && mousePosition.x < 1175 && mousePosition.y >= 125 && mousePosition.y < 660 && clickedseedPacket[1] == true && FIELD_GAME_STATUS[gridX - 3][gridY - 1] == false)
                {
                    AllPlants.getPlant(totalplanttypes - 1, totaltypescreated - 1).getPlantSprite().setPosition(gridX * 100.66 + 20, gridY * 114);
                    AllPlants.getPlant(totalplanttypes - 1, totaltypescreated - 1).setXgridcoordinate(gridX);
                    AllPlants.getPlant(totalplanttypes - 1, totaltypescreated - 1).setYgridcoordinate(gridY);
                    totaltypescreated++;

                    FIELD_GAME_STATUS[gridX - 3][gridY - 1] = true;  // So another plant cant be placed on the same spot

                    clickedseedPacket[0] = false;
                }
                              
            }            
        }
       
        
        // Convert mouse position to grid coordinates

       
    }
}



void Game::handleMouseInput(sf::RenderWindow& window)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        int gridX = 0;
        int gridY = 0;

        // Get the mouse position relative to the window
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

        gridX = (mousePosition.x / 100.66);
        gridY = (mousePosition.y / 114);

        if (mousePosition.x > 52 && mousePosition.x <= 191 && mousePosition.y >= 144 && mousePosition.y <= 233)
        {
            isPlacingPlant = true;
        }
        // Convert mouse position to grid coordinates
        else if (mousePosition.x >= 305 && mousePosition.x < 1175 && mousePosition.y >= 125 && mousePosition.y < 660 && isPlacingPlant == true && FIELD_GAME_STATUS[gridY - 1][gridX - 3] == false)
        {
            cout << "Plant placed";
            shooters = new PeaShooter;
            shooters = &PeaShooterPlant;

            // Update the position of the plant sprite
            shooters->getPlantSprite().setPosition(gridX * 100.66 + 20, gridY * 114);
            shooters->setXgridcoordinate(gridX);
            shooters->setYgridcoordinate(gridY);

            FIELD_GAME_STATUS[gridY - 1][gridX - 3] = true;  // So another plant cant be placed on the same spot
            
            isPlacingPlant = false;
        }
        else
        {
            isPlacingPlant = false;
        }
        
    }
}




void Game::setPlantTextures()
{
    shooters = &PeaShooterPlant;

    sf::IntRect textureRect(0, 0, 27.125, 31);  // x = 0, y = 0, width = 64, height = 64

    shooters->getPlantSprite().setTexture(Asset_Texture.getTexture(1));  // Set the texture of the plant
    shooters->getPlantSprite().setTextureRect(textureRect);

   

    shooters->getPlantSprite().setScale(3, 3);  // Scale the sprite to make it appear larger
    textureRect = sf::IntRect(78, 38, 10, 20);
    for (int i = 0; i < shooters->getMaxBullets(); i++)
    {
        shooters->getBullet(i).getBulletSprite().setTexture(Asset_Texture.getTexture(4));
        shooters->getBullet(i).getBulletSprite().setScale(3, 3);
        shooters->getBullet(i).getBulletSprite().setTextureRect(textureRect);
    }

    for (int i = 0; i < 5; i++) // setting textures of all plants (peashooter here)
    {
        AllPlants.getPlant(0, i).getPlantSprite().setTexture(Asset_Texture.getTexture(1)); // set texture of first type of plant(peashooter)
        AllPlants.getPlant(0, i).getPlantSprite().setTextureRect(textureRect); // set texture of first type of plant(peashooter)
        AllPlants.getPlant(0, i).getPlantSprite().setScale(3, 3);
    }
    



    shooters = NULL;  // Currently no plants exist
}

void Game::renderPlants(RenderWindow& window)
{
    window.draw(shooters->getPlantSprite());
    for (int i = 0; i < shooters->getMaxBullets(); i++)
    {
        shooters->getBullet(i).drawBullet(window);
    }
    
    for (int i = 0; i < 5; i++)
    {
        // window.draw(AllPlants.getPlant(0, i).getPlantSprite());
    }

    



    
 
}
void Game::renderUI(RenderWindow& window)
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
    Clock deltaClock;
    float deltaTime = 0.0;

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

        renderUI(window); // render the UI
        handleMouseInput(window);  // Handle mouse input
        // handlePlantCreation();
        if (shooters != NULL)
        {
            shooters->setAnimation(); // plant animation (will be a for loop inside setting animations for all plants)
            shooters->shootBullet(deltaTime); // shoot peas
            renderPlants(window); // plants 
        }
        
        // AllPlants.getPlant(0, 0).setAnimation();
        

        window.display();  
        window.clear();
    }
}