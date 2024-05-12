#include "LeaderBoardState.h"

void LeaderBoardState::Init(AssetManager& Assets)
{
	background.setTexture(Assets.getTexture(24));
}
void LeaderBoardState::HandleInput(StateMachine* machine, sf::RenderWindow& window)
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
void LeaderBoardState::Update(StateMachine* machine, float deltaTime)
{

}
void LeaderBoardState::Draw(sf::RenderWindow& window, float deltaTimew)
{
	window.draw(background);
	window.display();
	window.clear();
}