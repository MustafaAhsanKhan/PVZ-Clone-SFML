#pragma once
#include "StateMachine.h"
#include "MainMenuState.h"
#include "Definitions.h"

class SplashState : public State
{
private:
	sf::Sprite background;
	sf::Clock displayTime;
public:
	SplashState() {}
	virtual void Init(AssetManager& Assets);
	virtual void HandleInput(StateMachine* machine, sf::RenderWindow& window);
	virtual void Update(StateMachine* machine, float deltaTime);
	virtual void Draw(sf::RenderWindow& window);
};