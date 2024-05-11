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

		if (mousePosition.x >= 111 && mousePosition.x <= 598 && mousePosition.y >= 176 && mousePosition.y <= 272)
		{
			machine->RemoveState();  // Going back to the main menu

			machine->AddState(StateRef(new Level1State));  // Replacing the meny state with the level 1 state
		}
	}
}
void LevelSelectionState::Update(StateMachine* machine, float deltaTime)
{

}
void LevelSelectionState::Draw(sf::RenderWindow& window)
{
	window.draw(background);
	window.display();
	window.clear();
}