#include "Game.h"
#include<iostream>
using namespace sf;

Game::Game()
{
    // plant = new Plant;
    plant = new Plant;
    
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


    // Bullet texture

   
    plant->setXgridcoordinate(1);
    plant->setYgridcoordinate(0);



    plant->getPlantSprite().setTexture(Asset_Texture.getTexture(1));  // Set the texture of the plant
    plant->getPlantSprite().setPosition((plant->getXgridcoordinate() * 142.2) + 15, (plant->getYgridcoordinate() * 144) + 10);  // + 15 x - axis, + 10 y - axis
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

        // Create a background
        plant->setAnimation();
        drawAll(window);
        
    }

    return;
}