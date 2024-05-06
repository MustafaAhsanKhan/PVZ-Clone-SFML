#pragma once
#include <memory>
#include <stack>
#include "State.h"

typedef std::unique_ptr<State> StateRef;  // A unique pointer to the state

class StateMachine
{
public:
	StateMachine() {}

	void AddState(StateRef p_newState, bool p_isReplacing = true);

	void RemoveState();

	void ProcessStateChanges();

	StateRef& GetActiveState();

	~StateMachine() {};
private:
	std::stack<StateRef> states;  // A stack of states
	StateRef newState;

	bool isRemoving;
	bool isAdding;
	bool isReplacing;

};