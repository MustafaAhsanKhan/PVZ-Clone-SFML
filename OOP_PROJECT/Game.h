#pragma once
#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
#include "Plant.h"
#include "PeaShooter.h"
#include "AssetManager.h"

using namespace sf;

// Key for the asset manager //

// 0 is the map texture
// 1 is the sun currency texture
// 2 is the sunflower texture
// 3 is the peashooter texture
// 4 is the pea bullet texture

class Game
{
private:
	RenderWindow window;  // The window of the game
	AssetManager Asset_Texture;  // The asset manager for the textures
	Plant* plant;  // The plant object
	PeaShooter PeaShooterPlant;
	Sprite mapSprite;
	Shooter* shooters;

public:

	Game();  // Default constructor
	void run(); // has the game loop

private:   // private functions
	void InitializeMapSprite();
	void InitializePlantTextures();
	void handleMouseInput(sf::RenderWindow& window);  // Handle the mouse input
	void setPlantTextures();
	void renderMap(RenderWindow& window);
	void renderPlants(RenderWindow& window);
};