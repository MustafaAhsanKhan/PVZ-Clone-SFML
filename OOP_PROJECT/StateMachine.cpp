#include "StateMachine.h"

void StateMachine::AddState(StateRef p_newState, bool p_isReplacing = true)
{
	isAdding = true;
	isReplacing = p_isReplacing;

	newState = std::move(p_newState);

}

void StateMachine::RemoveState()
{
	isRemoving = true;
}

void StateMachine::ProcessStateChanges()
{
	if (isRemoving == true  && !states.empty())
	{
		states.pop();

		if (!states.empty())  // If the stack is not empty
		{
			states.top()->Resume();  // Resume the top state
		}

		isRemoving = false;
	}

	if (isAdding == true)
	{
		if (!states.empty())  // If the stack is not empty
		{
			if (isReplacing)
			{
				states.pop();
			}
			else
			{
				states.top()->Pause();
			}
		}

		states.push(std::move(newState));
		states.top()->Init();
		isAdding = false;
	}
}

StateRef& StateMachine::GetActiveState()
{
	return states.top();
}