#pragma once
#include "Game.h"
#include "State.h"

class SplashState : public State , public Game
{
private:
	sf::Sprite background;
	sf::Clock displayTime;
public:
	SplashState() {}
	virtual void Init();
	virtual void HandleInput() {}
	virtual void Update();
	virtual void Draw();
};