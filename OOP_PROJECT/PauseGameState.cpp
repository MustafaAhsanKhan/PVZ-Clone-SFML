#include "PauseGameState.h"

void PauseGameState::Init(AssetManager& Assets)
{
	background.setTexture(Assets.getTexture(25));
	levelBackground.setTexture(Assets.getTexture(backgroundIndex));
	levelBackground.setColor(sf::Color(255, 255, 255, 50));
}
void PauseGameState::HandleInput(StateMachine* machine, sf::RenderWindow& window)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

		if (mousePosition.x >= 365 && mousePosition.x <= 911 && mousePosition.y >= 229 && mousePosition.y <= 339)
		{
			machine->RemoveState();  // Going back to the game
		}
		if (mousePosition.x >= 365 && mousePosition.x <= 911 && mousePosition.y >= 379 && mousePosition.y <= 485)
		{
			machine->RemoveState();  // Going back to the game
			machine->AddState(StateRef(new MainMenuState), true);  // Switching to the main menu
		}
		
	}
}
void PauseGameState::Update(StateMachine* machine, float deltaTime)
{

}
void PauseGameState::Draw(sf::RenderWindow& window, float deltaTime)
{
	window.draw(levelBackground);
	window.draw(background);
	window.display();
	window.clear();
}