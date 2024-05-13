#include "Game.h"

// int Game::totaltypescreated = 1; // current plant types created

Game::Game() : window(sf::VideoMode(1280, 720), "Plants Vs Zombies", sf::Style::Titlebar | sf::Style::Close)
{
    // Initialize the UI
	InitializeUISprites();

    // Game icon
    sf::Image icon;
    if (!icon.loadFromFile("../PVZ_Textures/icon.png"))
    {
        return;
    }
    window.setIcon(32, 32, icon.getPixelsPtr());
	InitializePlantTextures();
	InitializeZombieTextures();
}

void Game::InitializeMusic()
{
	// backgroundMusic.openFromFile("Sounds/backgroundMusic.mp3");
	// backgroundMusic.play();
}

void Game::InitializeUISprites()
{
    Assets.loadTexture(20, "../PVZ_Textures/backgrounds/LoadingScreen.png");
    Assets.loadTexture(21, "../PVZ_Textures/backgrounds/MainMenu.png");
    Assets.loadTexture(22, "../PVZ_Textures/backgrounds/LevelSelection.png");
    Assets.loadTexture(23, "../PVZ_Textures/backgrounds/Instructions.png");
    Assets.loadTexture(24, "../PVZ_Textures/backgrounds/LeaderBoard.png");
    Assets.loadTexture(25, "../PVZ_Textures/backgrounds/PauseScreen.png");
    Assets.loadTexture(26, "../PVZ_Textures/backgrounds/Level1.png");
    Assets.loadTexture(27, "../PVZ_Textures/backgrounds/Level2.png");
    Assets.loadTexture(28, "../PVZ_Textures/backgrounds/Level3.png");
    Assets.loadTexture(29, "../PVZ_Textures/backgrounds/Level4.png");
    Assets.loadTexture(30, "../PVZ_Textures/Seed_Packets_Sprites.png");
    Assets.loadTexture(31, "../PVZ_Textures/Lawn_Mower.png");
    Assets.loadTexture(32, "../PVZ_Textures/Lawn_Mower2.png");
    Assets.loadTexture(33, "../PVZ_Textures/Sun.png");
    Assets.loadTexture(34, "../PVZ_Textures/Shovel2.png");
}

void Game::InitializePlantTextures()
{
	Assets.loadTexture(1, "../PVZ_Textures/PlantTextures/Sunflower.png");
	Assets.loadTexture(2, "../PVZ_Textures/PlantTextures/Peashooter.png");
	Assets.loadTexture(3, "../PVZ_Textures/PlantTextures/Wallnut.png");
    Assets.loadTexture(4, "../PVZ_Textures/PlantTextures/Cherrybomb.png");
	Assets.loadTexture(5, "../PVZ_Textures/PlantTextures/Repeater.png");
	Assets.loadTexture(6, "../PVZ_Textures/PlantTextures/SnowPea.png");
	Assets.loadTexture(7, "../PVZ_Textures/PlantTextures/Peashooter.png");
	Assets.loadTexture(8, "../PVZ_Textures/PlantTextures/FumeShroom.png");
}

void Game::InitializeZombieTextures()
{
	Assets.loadTexture(10, "../PVZ_Textures/Zombies/simple_zombie.png");
    Assets.loadTexture(11, "../PVZ_Textures/Zombies/flying_zombie.png");
    Assets.loadTexture(12, "../PVZ_Textures/Zombies/football_zombie.png");
    Assets.loadTexture(13, "../PVZ_Textures/Zombies/dancing_zombie.png");
    Assets.loadTexture(14, "../PVZ_Textures/Zombies/backup_dancer_zombie.png");
    Assets.loadTexture(15, "../PVZ_Textures/Zombies/dolphin_rider_zombie.png");
}


void Game::run()
{
    srand(time(0));
    //window.setFramerateLimit(60);

    machine.AddState(StateRef(new MainMenuState));  // Change back to splash state
    
    float deltaTime = 0.0;
   
    while (window.isOpen())
    {
        machine.ProcessStateChanges(Assets);

        deltaTime = deltaClock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        
        machine.GetActiveState()->HandleInput(&machine, window);
        machine.GetActiveState()->Update(&machine, deltaTime);
        machine.GetActiveState()->Draw(window, deltaTime);
    }
}