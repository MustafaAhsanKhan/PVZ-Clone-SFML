#pragma once
#include "Stack.h"
#include "AssetManager.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <ctime>
#include <iostream>

class StateMachine;

class State
{
public:
	virtual void Init(AssetManager& Assets) = 0;

	virtual void HandleInput(StateMachine* machine, sf::RenderWindow& window) = 0;

	virtual void Update(StateMachine* machine, float deltaTime) = 0;

	virtual void Draw(sf::RenderWindow& window, float deltaTime) = 0;

	void Pause() {}

	void Resume() {}
};


typedef std::unique_ptr<State> StateRef;  // A unique pointer to the state

class StateMachine
{
public:
	StateMachine() {}

	void AddState(StateRef p_newState, bool p_isReplacing = true);

	void RemoveState();

	void ProcessStateChanges(AssetManager& Assets);

	StateRef& GetActiveState();

	~StateMachine() {};
private:
	Stack<StateRef> states;  // A stack of states
	StateRef newState;

	bool isRemoving;
	bool isAdding;
	bool isReplacing;

};