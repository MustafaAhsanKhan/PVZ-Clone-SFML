#pragma once
#include "StateMachine.h"
#include "PauseGameState.h"

#include "Plant.h"
#include "PeaShooter.h"
#include "PlantFactory.h"

#include "Zombie.h"
#include "SimpleZombie.h"
#include "FlyingZombie.h"
#include "FootballZombie.h"
#include "DancingZombie.h"
#include "DolphinRiderZombie.h"

class Level1State : public State
{
private:
	sf::Sprite background;
	sf::Sprite seedPacketSprite;
	sf::Sprite lawnMowerSprite[5];
	sf::Clock ElapsedTime;  // Used to keep track of time  // Generate sun  // Maybe spawn zombies

	// sf::Music backgroundMusic;
	sf::IntRect textureRect;
	bool FIELD_GAME_STATUS[5][9];  // The status of the game field

	PeaShooter PeaShooterPlant;
	PlantFactory AllPlants;

	Zombie* zombie;
	SimpleZombie SimpleZombie;
	FlyingZombie FlyingZombie;
	FootballZombie FootballZombie;
	DancingZombie DancingZombie;
	DolphinRiderZombie DolphinRiderZombie;

	//Shooter* shooters;
	bool isPlacingPlant;
	bool clickedSeedPacket[2]; // change size later
	int totaltypescreated = 1;
public:
	Level1State();
	//void setPlantTextures();
	void setPlantFactoryTextures(AssetManager& Assets);
	void setZombieTextures(AssetManager& Assets);
	void setUITextures(AssetManager& Assets);

	void handleAllPlantsCreation(sf::RenderWindow& window);
	//void handleMouseInput();  // Handle the mouse input	
	void renderPlantFactory(sf::RenderWindow& window);
	// void renderPlants();  // Render the plants
	void renderZombies(sf::RenderWindow& window);  // Render the zombies
	void renderUI(sf::RenderWindow& window);  // Render the UI

	virtual void Init(AssetManager& Assets);
	virtual void HandleInput(StateMachine* machine, sf::RenderWindow& window);
	virtual void Update(StateMachine* machine, float deltaTime);
	virtual void Draw(sf::RenderWindow& window);
};