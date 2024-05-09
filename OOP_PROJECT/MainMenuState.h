#pragma once
#include "StateMachine.h"
#include "Level1State.h"
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