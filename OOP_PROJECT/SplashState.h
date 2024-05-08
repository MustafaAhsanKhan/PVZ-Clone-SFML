#pragma once
#include "StateMachine.h"
#include "Level1State.h"
#include "Definitions.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <ctime>
#include <iostream>

class SplashState : public State
{
private:
	sf::Sprite background;
	sf::Clock displayTime;
public:
	SplashState() {}
	virtual void Init(AssetManager& Assets);
	virtual void HandleInput();
	virtual void Update(StateMachine* machine);
	virtual void Draw(sf::RenderWindow& window);
};