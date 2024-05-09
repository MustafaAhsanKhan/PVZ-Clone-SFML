#pragma once
#include "StateMachine.h"

class LeaderBoardState : public State
{
private:
	sf::Sprite background;
public:
	LeaderBoardState() {}
	virtual void Init(AssetManager& Assets);
	virtual void HandleInput(StateMachine* machine, sf::RenderWindow& window);
	virtual void Update(StateMachine* machine, float deltaTime);
	virtual void Draw(sf::RenderWindow& window);
};