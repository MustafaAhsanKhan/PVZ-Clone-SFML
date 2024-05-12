#include "MainMenuState.h"

void MainMenuState::Init(AssetManager& Assets)
{
	background.setTexture(Assets.getTexture(21));
}
void MainMenuState::HandleInput(StateMachine* machine, sf::RenderWindow& window)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

		if (mousePosition.x >= 402 && mousePosition.x <= 865 && mousePosition.y >= 279 && mousePosition.y <= 422)
		{
			machine->AddState(StateRef(new LevelSelectionState), false);  // Switching to the level selection screen
		}

		if (mousePosition.x >= 21 && mousePosition.x <= 522 && mousePosition.y >= 653 && mousePosition.y <= 689)
		{
			machine->AddState(StateRef(new InstructionsState), false);  // Switching to the instructions screen
		}

		if (mousePosition.x >= 770 && mousePosition.x <= 1255 && mousePosition.y >= 653 && mousePosition.y <= 689)
		{
			machine->AddState(StateRef(new LeaderBoardState), false);  // Switching to the leader board screen
		}
	}
}
void MainMenuState::Update(StateMachine* machine, float deltaTime)
{

}
void MainMenuState::Draw(sf::RenderWindow& window, float deltaTime)
{
	window.draw(background);
	window.display();
	window.clear();
}