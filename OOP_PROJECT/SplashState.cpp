#include "SplashState.h"


void SplashState::Init(AssetManager& Assets)
{
	// Initialize the background
	background.setTexture(Assets.getTexture(20));
}

void SplashState::HandleInput(StateMachine* machine, sf::RenderWindow& window)
{

}

void SplashState::Update(StateMachine* machine, float deltaTime)
{
		// If the time elapsed is greater than 3 seconds, switch to the main menu
	if (displayTime.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
	{
		// Change the state to the main menu
		cout << "Switching to the main menu" << endl;
		machine->AddState(StateRef(new MainMenuState));  // Replace the current state with the main menu
	}
}

void SplashState::Draw(sf::RenderWindow& window)
{
	window.draw(background);
	window.display();
	window.clear();
}