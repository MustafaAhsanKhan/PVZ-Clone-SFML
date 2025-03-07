#pragma once
#include "StateMachine.h"
#include "PauseGameState.h"
#include "Sun.h"
#include "Plant.h"
#include "PeaShooter.h"
#include "PlantFactory.h"
#include <cstdlib>
#include "ZombieFactory.h"
#include "LawnMower.h"
using namespace std;

class Level5State : public State
{
private:
	// UI Sprites
	sf::Sprite background;
	sf::Sprite seedPacketSprite;
	sf::Clock ZombieSpawnRate;  // Used to spawn zombies
	sf::Sprite shovelSprite;
	sf::Text elapsedTimeText;
	// UI features
	sf::Clock ElapsedTime;
	sf::Font font;
	sf::Text sunsNumText;
	sf::Clock sunClock;
	sf::Clock sunflowerSunClock;
	sf::Text livesText;

	// Sounds
	sf::SoundBuffer sungen_SoundBuffer;
	sf::Sound sungen_Sound;
	sf::SoundBuffer placingPlantSoundBuffer;
	sf::Sound zombieWave;
	sf::SoundBuffer zombieWaveBuffer;
	sf::Sound placingPlantSound;
	sf::Music backgroundMusic;
	sf::IntRect textureRect;

	// Game Objects
	PlantFactory AllPlants;
	ZombieFactory AllZombies;
	Sun* suns;
	LawnMower* lawnmowers;

	// Numbers for loops
	const int MAX_lawnmowers = 5;
	const int AllZombieTypes = 5;


	// Required variables
	int Lives;
	bool FIELD_GAME_STATUS[5][9];  // The status of the game field
	bool clickedSeedPacket[6]; // change size later
	bool clickedShovel;
	int totalTypeInstancesCreated = 1;
	int sunCount;
	int currentSuns = 0;
	int sunsNum;
	int totalShooterInstancesCreated = 1;
	int totalNormalPlantInstancesCreated = 1;
	bool leftMouseButtonPressed = false;
	const int totalPlantTypes = 6;
	int sunflowerInstances = 0;


public:
	Level5State();
private:
	void setPlantFactoryTextures(AssetManager& Assets);
	void setZombieTextures(AssetManager& Assets);
	void setUITextures(AssetManager& Assets);
	void handleAllPlantsCreation(sf::RenderWindow& window);
	void spawnZombies();  // Spawn the zombies
	void renderPlantFactory(sf::RenderWindow& window);
	void renderZombies(sf::RenderWindow& window, float deltaTime);
	void renderUI(sf::RenderWindow& window);
	void generateSuns(sf::RenderWindow& window, float deltaTime);
	void handleSunCollection(sf::RenderWindow& window);
	void handlePlantRemoval(sf::RenderWindow& window);
	void handleBulletZombieCollision(sf::RenderWindow& window);
	void handlePlantZombieCollision();
	void handleLawnMowerCollision(float deltaTime);
	virtual void Init(AssetManager& Assets);
	virtual void HandleInput(StateMachine* machine, sf::RenderWindow& window);
	virtual void Update(StateMachine* machine, float deltaTime);
	virtual void Draw(sf::RenderWindow& window, float deltaTime);
};

