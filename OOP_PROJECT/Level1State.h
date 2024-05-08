#pragma once
#include "StateMachine.h"

class Level1State : public State
{
private:
	sf::Sprite background;
public:
	Level1State() {}
	virtual void Init(AssetManager& Assets);
	virtual void HandleInput();
	virtual void Update(StateMachine* machine);
	virtual void Draw(sf::RenderWindow& window);
};