#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <ctime>
#include <iostream>

#include "Definitions.h"
#include "AssetManager.h"

#include "SplashState.h"
#include "MainMenuState.h"
#include "Level1State.h"


class Game
{
private:
	sf::Clock deltaClock;
	float deltaTime = 0.0;
	sf::RenderWindow window;  // The window of the game
	AssetManager Assets;  // The asset manager for the textures
	StateMachine machine;  // The state machine
public:
	Game();  // Default constructor
	void run(); // has the game loop
private:  
	void InitializeMusic();
	void InitializeUISprites();  // Initialize the UI sprites
	void InitializePlantTextures();  // Initialize the plant textures
	void InitializeZombieTextures();  // Initialize the zombie textures
};