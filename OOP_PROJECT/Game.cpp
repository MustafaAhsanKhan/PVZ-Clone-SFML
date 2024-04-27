#include "Game.h"
#include<iostream>
using namespace sf;

Game::Game()
{
    // plant = new Plant;
    plant = new Plant;
    shooters = new PeaShooter;
    
}

void Game::handleMouseInput(sf::RenderWindow& window)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        // Get the mouse position relative to the window
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

        // Convert mouse position to grid coordinates
        int gridX = (mousePosition.x - 15) / 142.2; // Assuming 15 is the offset for x-axis
        int gridY = (mousePosition.y - 10) / 144;   // Assuming 10 is the offset for y-axis

        // Update the position of the plant sprite
        shooters->getPlantSprite().setPosition(gridX * 142.2 + 15, gridY * 144 + 10);
        shooters->setXgridcoordinate(gridX);
        shooters->setYgridcoordinate(gridY);
        for (int i = 0; i < shooters->getMaxBullets(); i++)
        {
            shooters->getBullet(i).setXPos(gridX * 142.2 + 80);
            shooters->getBullet(i).setYPos(gridY * 144);
            shooters->getBullet(i).getBulletSprite().setScale(0.1, 0.1);
        }
        shooters->getBullet(0).setXPos(gridX * 142.2 + 80);
        shooters->getBullet(0).setYPos(gridY * 144);
        shooters->getBullet(0).getBulletSprite().setScale(0.1, 0.1);
        
    }
}

void Game::setObjectTextures()
{
    // Grid Texture
    Asset_Texture.loadTexture(0, "../starter_files/Images/grid.png");

    // Plant Textures
    Asset_Texture.loadTexture(1, "../PVZ_Textures/PlantTextures/Peashooter.png");
    Asset_Texture.loadTexture(2, "../PVZ_Textures/PlantTextures/sunflower.png");
    Asset_Texture.loadTexture(3, "../PVZ_Textures/PlantTextures/cherrybomb.png");
    Asset_Texture.loadTexture(4, "../PVZ_Textures/PlantTextures/wallnut.png");
    Asset_Texture.loadTexture(5, "../PVZ_Textures/PlantTextures/Pea.png");
    // Setting textures for sprites
    mapSprite.setTexture(Asset_Texture.getTexture(0));

    shooters = &PeaShooterPlant;

    sf::IntRect textureRect(0, 0, 27.125, 31);  // x = 0, y = 0, width = 64, height = 64


    shooters->getPlantSprite().setTexture(Asset_Texture.getTexture(1));  // Set the texture of the plant
    shooters->getPlantSprite().setTextureRect(textureRect);
    shooters->getPlantSprite().setScale(3.75, 3.75);  // Scale the sprite to make it appear larger
    for (int i = 0; i < shooters->getMaxBullets(); i++)
    {
        shooters->getBullet(i).getBulletSprite().setTexture(Asset_Texture.getTexture(5));
        shooters->getBullet(i).getBulletSprite().setScale(0.1, 0.1);
    }
    
    // shooters->getBullet(0).getBulletSprite().setPosition(100, 100);

}
void Game::drawAll(RenderWindow& window)
{
    window.draw(mapSprite);
    window.draw(shooters->getPlantSprite());
    shooters->getBullet(0).drawBullet(window);
    if (shooters->getBullet(0).getXPos() > 700) // change this to a clock that handles the rate of shooting
    {
        shooters->getBullet(1).drawBullet(window);
    }
    
    // window.draw(shooters->getBullet(0).getBulletSprite());
    window.display();
    window.clear();
}


void Game::run()
{
    RenderWindow window(VideoMode(1280, 720), "Plants Vs Zombies", sf::Style::Titlebar | sf::Style::Close);

    setObjectTextures();

    // Scale the sprite to fit the window size
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

    ///////////////////////////////////////

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
        // Create a background
        shooters->setAnimation();
        shooters->shootBullet();
        drawAll(window);
        
    }

    return;
}