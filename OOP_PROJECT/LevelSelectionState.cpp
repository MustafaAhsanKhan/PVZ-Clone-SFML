#include "LevelSelectionState.h"

void LevelSelectionState::Init(AssetManager& Assets)
{
	background.setTexture(Assets.getTexture(22));
}
void LevelSelectionState::HandleInput(StateMachine* machine, sf::RenderWindow& window)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

		if (mousePosition.x >= 33 && mousePosition.x <= 106 && mousePosition.y >= 31 && mousePosition.y <= 100)
		{
			machine->RemoveState();  // Going back to the main menu
		}

		else if (mousePosition.x >= 111 && mousePosition.x <= 598 && mousePosition.y >= 176 && mousePosition.y <= 272)
		{
			machine->RemoveState();  // Going back to the main menu
			machine->AddState(StateRef(new Level1State));  // Replacing the menu state with the level 1 state
		}

		else if (mousePosition.x >= 111 && mousePosition.x <= 598 && mousePosition.y >= 272 && mousePosition.y <= 368)
		{
			machine->RemoveState();  // Going back to the main menu
			machine->AddState(StateRef(new Level2State));  // Replacing the menu state with the level 2 state
		}

		else if (mousePosition.x >= 111 && mousePosition.x <= 598 && mousePosition.y >= 430 && mousePosition.y <= 555)
		{
			machine->RemoveState();  // Going back to the main menu
			machine->AddState(StateRef(new Level3State));  // Replacing the menu state with the level 3 state
		}

		else if (mousePosition.x >= 709 && mousePosition.x <= 1196 && mousePosition.y >= 176 && mousePosition.y <= 272)
		{
			machine->RemoveState();  // Going back to the main menu
			machine->AddState(StateRef(new Level4State));  // Replacing the menu state with the level 4 state
		}
		
		else if (mousePosition.x >= 696 && mousePosition.x <= 1196 && mousePosition.y >= 272 && mousePosition.y <= 368)
		{
			machine->RemoveState();  // Going back to the main menu
			machine->AddState(StateRef(new Level5State));  // Replacing the menu state with the level 5 state
		}
		
		else if (mousePosition.x >= 696 && mousePosition.x <= 1196 && mousePosition.y >= 430 && mousePosition.y <= 555)
		{
			machine->RemoveState();  // Going back to the main menu
			machine->AddState(StateRef(new Level6State));  // Replacing the meny state with the level 6 state
		}


	}
}
void LevelSelectionState::Update(StateMachine* machine, float deltaTime)
{

}
void LevelSelectionState::Draw(sf::RenderWindow& window, float deltaTime)
{
	window.draw(background);
	window.display();
	window.clear();
}