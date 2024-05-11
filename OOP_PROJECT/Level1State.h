 #pragma once
#include "StateMachine.h"
#include "PauseGameState.h"

#include "Plant.h"
#include "PeaShooter.h"
#include "PlantFactory.h"

#include "ZombieFactory.h"

class Level1State : public State
{
private:
	sf::Sprite background;
	sf::Sprite seedPacketSprite;
	sf::Sprite lawnMowerSprite[5];
	sf::Clock ElapsedTime;  // Used to keep track of time  // Generate sun  // Maybe spawn zombies
	sf::Clock ZombieSpawnRate;  // Used to spawn zombies

	// sf::Music backgroundMusic;
	sf::IntRect textureRect;
	bool FIELD_GAME_STATUS[5][9];  // The status of the game field

	PeaShooter PeaShooterPlant;
	PlantFactory AllPlants;

	ZombieFactory AllZombies;

	//Shooter* shooters;
	//bool isPlacingPlant;
	bool clickedSeedPacket[7]; // change size later
	int totalTypeInstancesCreated = 1;
	sf::SoundBuffer placingPlantSound;
public:
	Level1State();
	//void setPlantTextures();
	void setPlantFactoryTextures(AssetManager& Assets);
	void setZombieTextures(AssetManager& Assets);
	void setUITextures(AssetManager& Assets);

	void handleAllPlantsCreation(sf::RenderWindow& window);
	void spawnZombies();  // Spawn the zombies
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