#include "Game.h"
#include<iostream>
using namespace sf;

Game::Game() : window(sf::VideoMode(1280, 720), "Plants Vs Zombies", sf::Style::Titlebar | sf::Style::Close)
{
    // Initialize Plants
    plant = new Plant; // will handle the plants array later
    shooters = new PeaShooter;
    
    // Initialize Map
    InitializeMapSprite();
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

void Game::InitializeMapSprite()
{
    Asset_Texture.loadTexture(0, "../PVZ_Textures/backgrounds/level2.png");
    mapSprite.setTexture(Asset_Texture.getTexture(0));
}

void Game::InitializePlantTextures()
{
    Asset_Texture.loadTexture(1, "../PVZ_Textures/PlantTextures/Peashooter.png");
    Asset_Texture.loadTexture(2, "../PVZ_Textures/PlantTextures/sunflower.png");
    Asset_Texture.loadTexture(3, "../PVZ_Textures/PlantTextures/cherrybomb.png");
    Asset_Texture.loadTexture(4, "../PVZ_Textures/PlantTextures/wallnut.png");
    Asset_Texture.loadTexture(5, "../PVZ_Textures/PlantTextures/Pea.png");
}

void Game::handleMouseInput(sf::RenderWindow& window)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        // Get the mouse position relative to the window
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

        int gridX = 0;
        int gridY = 0;

        // Convert mouse position to grid coordinates
        if (mousePosition.x >= 305 && mousePosition.x < 1175 && mousePosition.y >= 125 && mousePosition.y < 660)
        {

            gridX = (mousePosition.x / 100.66);
            gridY = (mousePosition.y / 114);

            // Update the position of the plant sprite
            shooters->getPlantSprite().setPosition(gridX * 100.66 + 20, gridY * 114);
            shooters->setXgridcoordinate(gridX);
            shooters->setYgridcoordinate(gridY);
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
    for (int i = 0; i < shooters->getMaxBullets(); i++)
    {
        shooters->getBullet(i).getBulletSprite().setTexture(Asset_Texture.getTexture(5));
        shooters->getBullet(i).getBulletSprite().setScale(0.1, 0.1);
    }

}

void Game::renderPlants(RenderWindow& window)
{
    window.draw(shooters->getPlantSprite());
    for (int i = 0; i < shooters->getMaxBullets(); i++)
    {
        shooters->getBullet(i).drawBullet(window);
    }
 
}
void Game::renderMap(RenderWindow& window)
{
    window.draw(mapSprite);
}


void Game::run()
{
    /*
    NOTE : THIS CODE IS EXTRA AND WE MIGHT NEED IT LATER BUT NOW
    // Game field (5x9)
    const int ROWS = 5;
    const int COLS = 9;

    bool FIELD_GAME_STATUS[ROWS][COLS];

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            FIELD_GAME_STATUS[i][j] = true;
        }
    }
    */

    Clock deltaClock;
    float deltaTime = 0.0f;
    while (window.isOpen())
    {
        deltaTime = deltaClock.getElapsedTime().asMicroseconds();
        deltaClock.restart();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        handleMouseInput(window);  // Handle mouse input
        shooters->setAnimation(); // plant animation (will be a for loop inside setting animations for all plants)
        shooters->shootBullet(); // shoot peas
        window.clear();
        renderMap(window); // map
        renderPlants(window); // plants 
        window.display();  
    }
}