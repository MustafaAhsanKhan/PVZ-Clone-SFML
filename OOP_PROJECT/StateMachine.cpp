#include "StateMachine.h"

void StateMachine::AddState(StateRef p_newState, bool p_isReplacing)
{
	isAdding = true;
	isReplacing = p_isReplacing;

	newState = std::move(p_newState);

}

void StateMachine::RemoveState()
{
	isRemoving = true;
}

void StateMachine::ProcessStateChanges(AssetManager& Assets)
{
	if (isRemoving == true  && !states.isEmpty())
	{
		states.pop();

		if (!states.isEmpty())  // If the stack is not empty
		{
			states.gettop()->Resume();  // Resume the top state
		}

		isRemoving = false;
	}

	if (isAdding == true)
	{
		if (!states.isEmpty())  // If the stack is not empty
		{
			if (isReplacing)
			{
				states.pop();
			}
			else
			{
				states.gettop()->Pause();
			}
		}

		states.push(std::move(newState));
		states.gettop()->Init(Assets);
		isAdding = false;
	}
}

StateRef& StateMachine::GetActiveState()
{
	return states.gettop();
}