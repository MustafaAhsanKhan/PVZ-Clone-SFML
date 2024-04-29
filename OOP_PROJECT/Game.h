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
	bool FIELD_GAME_STATUS[5][9];
	RenderWindow window;  // The window of the game
	AssetManager Asset_Texture;  // The asset manager for the textures
	Plant* plant;  // The plant object
	PeaShooter PeaShooterPlant;
	Sprite mapSprite;
	Sprite seedPacketSprite;
	Sprite lawnMowerSprite[5];
	Shooter* shooters;
	bool isPlacingPlant;
public:
	Game();  // Default constructor
	void run(); // has the game loop
private: 
	void InitializeUISprites();
	void InitializePlantTextures();
	void InitializeZombieTextures();
	void handleMouseInput(sf::RenderWindow& window);  // Handle the mouse input
	void setPlantTextures();
	void renderUI(RenderWindow& window);
	void renderPlants(RenderWindow& window);

};