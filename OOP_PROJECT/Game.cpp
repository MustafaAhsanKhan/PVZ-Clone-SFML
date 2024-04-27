#include "Game.h"
#include<iostream>
using namespace sf;

Game::Game()
{
    // plant = new Plant;
    plant = new Plant;
    
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
        plant->getPlantSprite().setPosition(gridX * 142.2 + 15, gridY * 144 + 10);
        plant->setXgridcoordinate(gridX);
        plant->setYgridcoordinate(gridY);
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

    // Setting textures for sprites
    mapSprite.setTexture(Asset_Texture.getTexture(0));

    plant = &PeaShooterPlant;

    sf::IntRect textureRect(0, 0, 27.125, 31);  // x = 0, y = 0, width = 64, height = 64


    plant->getPlantSprite().setTexture(Asset_Texture.getTexture(1));  // Set the texture of the plant
    plant->getPlantSprite().setTextureRect(textureRect);
    plant->getPlantSprite().setScale(3.75, 3.75);  // Scale the sprite to make it appear larger
}
void Game::drawAll(RenderWindow& window)
{
    window.draw(mapSprite);
    window.draw(plant->getPlantSprite());
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
        plant->setAnimation();
        drawAll(window);
        
    }

    return;
}