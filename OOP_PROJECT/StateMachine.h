#pragma once
#include <memory>
#include <stack>
#include "AssetManager.h"

class StateMachine;

class State
{
public:
	virtual void Init(AssetManager& Assets) = 0;

	virtual void HandleInput() = 0;

	virtual void Update(StateMachine* machine) = 0;  // DeltaTime?

	virtual void Draw(sf::RenderWindow& window) = 0;  // DeltaTime?

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
	std::stack<StateRef> states;  // A stack of states
	StateRef newState;

	bool isRemoving;
	bool isAdding;
	bool isReplacing;

};