#pragma once
#include "StateMachine.h"
#include "MainMenuState.h"

class PauseGameState : public State
{
private:
	sf::Sprite background;
	sf::Sprite levelBackground;
	int backgroundIndex;
public:
	PauseGameState() {}
	PauseGameState(int p_backgroundIndex) { backgroundIndex = p_backgroundIndex; }
	virtual void Init(AssetManager& Assets);
	virtual void HandleInput(StateMachine* machine, sf::RenderWindow& window);
	virtual void Update(StateMachine* machine, float deltaTime);
	virtual void Draw(sf::RenderWindow& window);
};