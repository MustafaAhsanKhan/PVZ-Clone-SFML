#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <ctime>
#include <iostream>

#include "Definitions.h"
#include "AssetManager.h"
#include "StateMachine.h"

#include "Plant.h"
#include "PeaShooter.h"
#include "PlantFactory.h"

#include "Zombie.h"
#include "SimpleZombie.h"
#include "FlyingZombie.h"
#include "FootballZombie.h"
#include "DancingZombie.h"
#include "DolphinRiderZombie.h"

using namespace sf;

class Game
{
protected:
	// sf::Music backgroundMusic;
	sf::Clock deltaClock;
	float deltaTime = 0.0;
	sf::IntRect textureRect;
	bool FIELD_GAME_STATUS[5][9];  // The status of the game field
	RenderWindow window;  // The window of the game
	AssetManager Assets;  // The asset manager for the textures
	StateMachine machine;  // The state machine
	// Plant* plant;  // The plant object
	PlantFactory AllPlants;

	Zombie* zombie;
	SimpleZombie SimpleZombie;
	FlyingZombie FlyingZombie;
	FootballZombie FootballZombie;
	DancingZombie DancingZombie;
	DolphinRiderZombie DolphinRiderZombie;

	Sprite mapSprite;
	Sprite seedPacketSprite;
	Sprite lawnMowerSprite[5];
	//Shooter* shooters;
	bool isPlacingPlant;
	bool clickedSeedPacket[2]; // change size later
	int totaltypescreated = 1;
public:
	Game();  // Default constructor
	void run(); // has the game loop
protected:  
	void InitializeMusic();
	void InitializeUISprites();  // Initialize the UI sprites
	void InitializePlantTextures();  // Initialize the plant textures
	void InitializeZombieTextures();  // Initialize the zombie textures
	//void setPlantTextures();
	void setPlantFactoryTextures();
	void setZombieTextures();
	void handleAllPlantsCreation();
	//void handleMouseInput();  // Handle the mouse input	
	void renderPlantFactory();
	// void renderPlants();  // Render the plants
	void renderZombies();  // Render the zombies
	void renderUI();  // Render the UI


};