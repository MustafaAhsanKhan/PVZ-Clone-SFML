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
	PeaShooter PeaShooter_plant;
	Sprite mapSprite;

public:
	Game();  // Default constructor

	void setObjectTextures();

	void drawAll(RenderWindow& window);  // Draw all the objects in the game

	void run();  // The whole game is inside this 

};