#pragma once
#include "StateMachine.h"
#include "InstructionsState.h"
#include "LeaderBoardState.h"
#include "LevelSelectionState.h"

class MainMenuState : public State
{
private:
	sf::Sprite background;
public:
	MainMenuState() {}
	virtual void Init(AssetManager& Assets);
	virtual void HandleInput(StateMachine* machine, sf::RenderWindow& window);
	virtual void Update(StateMachine* machine, float deltaTime);
	virtual void Draw(sf::RenderWindow& window);
};