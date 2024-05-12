#include "InstructionsState.h"

void InstructionsState::Init(AssetManager& Assets)
{
	background.setTexture(Assets.getTexture(23));
}
void InstructionsState::HandleInput(StateMachine* machine, sf::RenderWindow& window)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

		if (mousePosition.x >= 33 && mousePosition.x <= 106 && mousePosition.y >= 31 && mousePosition.y <= 100)
		{
			machine->RemoveState();  // Going back to the main menu
		}
	}
}
void InstructionsState::Update(StateMachine* machine, float deltaTime)
{

}
void InstructionsState::Draw(sf::RenderWindow& window, float deltaTime)
{
	window.draw(background);
	window.display();
	window.clear();
}