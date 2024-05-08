#include "Level1State.h"

void Level1State::Init(AssetManager& Assets)
{
	background.setTexture(Assets.getTexture(29));
}
void Level1State::HandleInput() {}
void Level1State::Update(StateMachine* machine)
{
	cout << "ENTERED THE LEVEL 1 STATE\n";
}
void Level1State::Draw(sf::RenderWindow& window)
{
	window.draw(background);
	window.display();
	window.clear();
}