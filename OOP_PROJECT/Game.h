#pragma once
#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
#include "Plant.h"
#include "PeaShooter.h"
#include "AssetManager.h"
#include "PlantFactory.h"

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
	bool FIELD_GAME_STATUS[5][9];  // The status of the game field
	RenderWindow window;  // The window of the game
	AssetManager Asset_Texture;  // The asset manager for the textures
	Plant* plant;  // The plant object
	PeaShooter PeaShooterPlant;

	PlantFactory AllPlants;

	Sprite mapSprite;
	Sprite seedPacketSprite;
	Sprite lawnMowerSprite[5];
	Shooter* shooters;
	bool isPlacingPlant;
	bool clickedseedPacket[2]; // change size later
public:
	Game();  // Default constructor
	void run(); // has the game loop
private:  
	void handlePlantCreation();
	void InitializeUISprites();  // Initialize the UI sprites
	void InitializePlantTextures();  // Initialize the plant textures
	void InitializeZombieTextures();  // Initialize the zombie textures
	void handleMouseInput(sf::RenderWindow& window);  // Handle the mouse input
	void setPlantTextures();
	void renderUI(RenderWindow& window);  // Render the UI
	void renderPlants(RenderWindow& window);  // Render the plants

};