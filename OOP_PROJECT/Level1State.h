 #pragma once
#include "StateMachine.h"
#include "PauseGameState.h"
#include "Sun.h"
#include "Plant.h"
#include "PeaShooter.h"
#include "PlantFactory.h"

#include "ZombieFactory.h"

class Level1State : public State
{
private:
	// UI Sprites
	sf::Sprite background;
	sf::Sprite seedPacketSprite;
	sf::Sprite lawnMowerSprite[5];
	sf::Clock ZombieSpawnRate;  // Used to spawn zombies
	sf::Sprite shovelSprite;

	// UI features
	sf::Clock ElapsedTime;
	sf::Font font;
	sf::Text sunsNumText;
	sf::Clock sunClock;
	
	// Sounds
	sf::SoundBuffer sungen_SoundBuffer;
	sf::Sound sungen_Sound;
	sf::SoundBuffer placingPlantSoundBuffer;
	sf::Sound placingPlantSound;
	// sf::Music backgroundMusic;
	sf::IntRect textureRect;

	PlantFactory AllPlants;

	ZombieFactory AllZombies;

	Sun* suns;

	// Required variables
	bool FIELD_GAME_STATUS[5][9];  // The status of the game field
	bool clickedSeedPacket[7]; // change size later
	bool clickedShovel;
	int totalTypeInstancesCreated = 1;
	int sunCount;
	int currentSuns;
	int sunsNum;
	int totalShooterInstancesCreated = 1;
	int totalNormalPlantInstancesCreated = 1;
	bool leftMouseButtonPressed = false;	
	
public:
	Level1State();
	void setPlantFactoryTextures(AssetManager& Assets);
	void setZombieTextures(AssetManager& Assets);
	void setUITextures(AssetManager& Assets);
	void handleAllPlantsCreation(sf::RenderWindow& window);
	void spawnZombies();  // Spawn the zombies
	void renderPlantFactory(sf::RenderWindow& window);
	void renderZombies(sf::RenderWindow& window); 
	void renderUI(sf::RenderWindow& window); 
	void generateSuns(sf::RenderWindow& window);
	void handleSunCollection(sf::RenderWindow& window);
	void handlePlantRemoval(sf::RenderWindow& window);
	virtual void Init(AssetManager& Assets);
	virtual void HandleInput(StateMachine* machine, sf::RenderWindow& window);
	virtual void Update(StateMachine* machine, float deltaTime);
	virtual void Draw(sf::RenderWindow& window);

};