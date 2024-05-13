#pragma once
#include "StateMachine.h"
#include "Level1State.h"
#include "Level2State.h"
#include "Level3State.h"
#include "Level4State.h"
#include "Level5State.h"
#include "Level6State.h"

class LevelSelectionState : public State
{
private:
	sf::Sprite background;
public:
	LevelSelectionState() {}
	virtual void Init(AssetManager& Assets);
	virtual void HandleInput(StateMachine* machine, sf::RenderWindow& window);
	virtual void Update(StateMachine* machine, float deltaTime);
	virtual void Draw(sf::RenderWindow& window, float deltaTime);
};