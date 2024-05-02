#pragma once
#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
#include "Plant.h"
#include "PeaShooter.h"
#include "AssetManager.h"
#include "PlantFactory.h"

#include "Zombie.h"
#include "SimpleZombie.h"
#include "FlyingZombie.h"

using namespace sf;

class Game
{
private:
	bool FIELD_GAME_STATUS[5][9];  // The status of the game field
	RenderWindow window;  // The window of the game
	AssetManager Asset_Texture;  // The asset manager for the textures
	Plant* plant;  // The plant object
	PeaShooter PeaShooterPlant;
	SunFlower SunFlowerPlant;
	PlantFactory AllPlants;
	Zombie* zombie;
	SimpleZombie SimpleZombie;
	FlyingZombie FlyingZombie;
	Sprite mapSprite;
	Sprite seedPacketSprite;
	Sprite lawnMowerSprite[5];
	Shooter* shooters;
	bool isPlacingPlant;
	bool clickedSeedPacket[2]; // change size later
	int totaltypescreated = 1;
public:
	Game();  // Default constructor
	void run(); // has the game loop
private:  
	void InitializeUISprites();  // Initialize the UI sprites
	void InitializePlantTextures();  // Initialize the plant textures
	void InitializeZombieTextures();  // Initialize the zombie textures
	void setPlantTextures();
	void setZombieTextures();
	void handleAllPlantsCreation();
	void handlePlantCreation();	
	void handleMouseInput(sf::RenderWindow& window);  // Handle the mouse input	
	void renderPlantFactory();
	void renderPlants(RenderWindow& window);  // Render the plants
	void renderZombies(RenderWindow& window);  // Render the zombies
	void renderUI(RenderWindow& window);  // Render the UI


};