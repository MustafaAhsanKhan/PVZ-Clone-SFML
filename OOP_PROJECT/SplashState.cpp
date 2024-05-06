#include "SplashState.h"


void SplashState::Init()
{
	// Initialize the background
	background.setTexture(Game::Assets.getTexture(20));
}

void SplashState::Update()
{
		// If the time elapsed is greater than 3 seconds, switch to the main menu
	if (displayTime.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
	{
		// Change the state to the main menu
		//cout << "Switching to the main menu" << endl;
	}
}

void SplashState::Draw()
{
	Game::window.draw(background);
	Game::window.display();
	Game::window.clear();
}