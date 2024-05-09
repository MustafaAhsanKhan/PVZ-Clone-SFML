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

		if (mousePosition.x >= 416 && mousePosition.x <= 897 && mousePosition.y >= 100 && mousePosition.y <= 230)
		{
			machine->AddState(StateRef(new Level1State));
		}
	}
}
void MainMenuState::Update(StateMachine* machine, float deltaTime)
{

}
void MainMenuState::Draw(sf::RenderWindow& window)
{
	window.draw(background);
	window.display();
	window.clear();
}