#include "Level1State.h"

Level1State::Level1State()
{
    /*for (int i = 0; i < 10; i++)
    {
        AllPlants.getShooter(0, i).getPlantSprite().setPosition(-100, -100);
    }

    plant->getPlantSprite().setPosition(-100, -100);*/

    int temp = rand() % 5;

    zombie = &SimpleZombie;
    zombie->setXgridCoordinate(8);
    zombie->setYgridCoordinate(temp);
    zombie->setx_pos(1180);
    zombie->sety_pos((120 * temp) + 40);


    temp = rand() % 5;
    zombie = &FlyingZombie;

    zombie->setXgridCoordinate(8);
    zombie->setYgridCoordinate(temp);
    zombie->setx_pos(1180);
    zombie->sety_pos((120 * temp) + 40);

    temp = rand() % 5;
    zombie = &FootballZombie;

    zombie->setXgridCoordinate(8);
    zombie->setYgridCoordinate(temp);
    zombie->setx_pos(1180);
    zombie->sety_pos((120 * temp) + 40);

    temp = rand() % 5;
    zombie = &DancingZombie;

    zombie->setXgridCoordinate(8);
    zombie->setYgridCoordinate(temp);
    zombie->setx_pos(1180);
    zombie->sety_pos((120 * temp) + 40);

    temp = rand() % 5;
    zombie = &DolphinRiderZombie;

    zombie->setXgridCoordinate(8);
    zombie->setYgridCoordinate(temp);
    zombie->setx_pos(1180);
    zombie->sety_pos((120 * temp) + 40);
}

void Level1State::setPlantFactoryTextures(AssetManager& Assets)
{
    textureRect = sf::IntRect(0, 0, 27.125, 31);  // Peashooter
    for (int i = 0; i < 50; i++) // 50 plants
    {
        AllPlants.getShooter(0, i).getPlantSprite().setTexture(Assets.getTexture(0));
        AllPlants.getShooter(0, i).getPlantSprite().setTextureRect(textureRect);
        AllPlants.getShooter(0, i).getPlantSprite().setScale(3, 3);

    }

    // the Shooter's bullets
    textureRect = sf::IntRect(78, 38, 10, 20);
    for (int i = 0; i < 50; i++) // 50 plants
    {
        for (int j = 0; j < AllPlants.getShooter(0, i).getMaxBullets(); j++)
        {
            AllPlants.getShooter(0, i).getBullet(j).getBulletSprite().setTexture(Assets.getTexture(3));
            AllPlants.getShooter(0, i).getBullet(j).getBulletSprite().setScale(3, 3);
            AllPlants.getShooter(0, i).getBullet(j).getBulletSprite().setTextureRect(textureRect);
        }

    }

}

void Level1State::setZombieTextures(AssetManager& Assets)
{
    zombie = &SimpleZombie;

    textureRect = sf::IntRect(0, 58.28, 51.11, 58.28);

    zombie->getZombieSprite().setTexture(Assets.getTexture(10));
    zombie->getZombieSprite().setScale(3, 3);

    zombie->getZombieSprite().setTextureRect(textureRect);

    zombie = &FlyingZombie;

    textureRect = sf::IntRect(0, 0, 34.95, 58);
    zombie->getZombieSprite().setTexture(Assets.getTexture(11));
    zombie->getZombieSprite().setScale(3, 3);

    zombie->getZombieSprite().setTextureRect(textureRect);

    zombie = &FootballZombie;
    textureRect = sf::IntRect(0, 67.74, 64, 67.74);
    zombie->getZombieSprite().setTexture(Assets.getTexture(12));
    zombie->getZombieSprite().setScale(2.5, 2.5);
    zombie->getZombieSprite().setTextureRect(textureRect);

    zombie = &DancingZombie;
    textureRect = sf::IntRect(0, 80, 56, 80);
    zombie->getZombieSprite().setTexture(Assets.getTexture(13));
    zombie->getZombieSprite().setScale(2.2, 2.2);
    zombie->getZombieSprite().setTextureRect(textureRect);
}

void Level1State::setUITextures(AssetManager& Assets)
{
    sf::IntRect textureRect(0, 73, 143, 550);

    // Seed packet sprite
    seedPacketSprite.setTexture(Assets.getTexture(30));
    seedPacketSprite.setTextureRect(textureRect);
    seedPacketSprite.setPosition(50, 70);

    // Lawn mower sprite
    for (int i = 0; i < 5; i++)
    {
        lawnMowerSprite[i].setTexture(Assets.getTexture(31));
        lawnMowerSprite[i].setPosition(185, (i * 118) + 70);
    }
}

void Level1State::handleAllPlantsCreation(sf::RenderWindow& window)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        int gridX = 0;
        int gridY = 0;


        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

        gridX = (mousePosition.x / 100.66) - 3;
        gridY = (mousePosition.y / 114) - 1;

        const int totalplanttypes = 1; // will be 6 once all are implemented
        const int eachtypenum = 5; // total types
        // int totaltypescreated = 1; // the total instances of each type currently
        int plantscreated = 1; // currently

        // checks if seed packet clicked
        if (mousePosition.x > 52 && mousePosition.x <= 191 && mousePosition.y >= 55 && mousePosition.y <= 144)
        {
            clickedSeedPacket[0] = true;
        }
        if (mousePosition.x > 52 && mousePosition.x <= 191 && mousePosition.y >= 144 && mousePosition.y <= 233)
        {
            if (!clickedSeedPacket[0])
            {
                clickedSeedPacket[1] = true;
            }

        }
        for (int i = 0; i < totalplanttypes; i++)
        {

            if (mousePosition.x >= 305 && mousePosition.x < 1175 && mousePosition.y >= 125 && mousePosition.y < 660 && clickedSeedPacket[1] == true && FIELD_GAME_STATUS[gridY][gridX] == false)
            {
                AllPlants.getShooter(totalplanttypes - 1, totaltypescreated - 1).getPlantSprite().setPosition(gridX * 100.66 + 315, gridY * 114 + 115);
                AllPlants.getShooter(totalplanttypes - 1, totaltypescreated - 1).setXgridCoordinate(gridX);
                AllPlants.getShooter(totalplanttypes - 1, totaltypescreated - 1).setYgridCoordinate(gridY);
                AllPlants.getShooter(totalplanttypes - 1, totaltypescreated - 1).setExists(true);
                totaltypescreated++;
                cout << "NEW PLANT CREATED! ";
                FIELD_GAME_STATUS[gridY][gridX] = true;  // So another plant cant be placed on the same spot
                clickedSeedPacket[1] = false;
            }
        }
    }
}

void Level1State::renderPlantFactory(sf::RenderWindow& window)
{

    for (int i = 0; i < 50; i++) // all plants
    {
        if (AllPlants.getShooter(0, i).exists()) // check if exists then draw plant
        {
            window.draw(AllPlants.getShooter(0, i).getPlantSprite());
        }
        for (int j = 0; j < AllPlants.getShooter(0, i).getMaxBullets(); j++)
        {
            AllPlants.getShooter(0, i).getBullet(j).drawBullet(window); // already checking existence
        }
    }


}

void Level1State::renderZombies(sf::RenderWindow& window)
{
    zombie = &FlyingZombie;
    window.draw(zombie->getZombieSprite());

    zombie = &SimpleZombie;
    window.draw(zombie->getZombieSprite());

    zombie = &FootballZombie;
    window.draw(zombie->getZombieSprite());

    zombie = &DancingZombie;
    window.draw(zombie->getZombieSprite());
    
}

void Level1State::renderUI(sf::RenderWindow& window)
{
    for (int i = 0; i < 5; i++)
    {
        window.draw(lawnMowerSprite[i]);
    }
    window.draw(seedPacketSprite);  // Draw the seed packet (Buttons)
}

void Level1State::Init(AssetManager& Assets)
{
	background.setTexture(Assets.getTexture(26));
    setPlantFactoryTextures(Assets);
    setZombieTextures(Assets);
    setUITextures(Assets);
}
void Level1State::HandleInput(StateMachine* machine, sf::RenderWindow& window)
{
    handleAllPlantsCreation(window);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

        if (mousePosition.x >= 1165 && mousePosition.x <= 1252 && mousePosition.y >= 31 && mousePosition.y <= 112)
        {
            machine->AddState(StateRef(new PauseGameState(26)), false);  // Switching to the Pause game state
        }
    }
}
void Level1State::Update(StateMachine* machine, float deltaTime)
{
	//cout << "ENTERED THE LEVEL 1 STATE\n";

    for (int i = 0; i < totaltypescreated; i++)
    {
        AllPlants.getShooter(0, i).setAnimation();
        AllPlants.getShooter(0, i).shootBullet(deltaTime);
    }

    if (zombie != nullptr)
    {
        zombie = &FlyingZombie;
        zombie->moveZombie(deltaTime);
        zombie->setAnimation();

        zombie = &SimpleZombie;
        zombie->moveZombie(deltaTime);
        zombie->setAnimation();

        zombie = &FootballZombie;
        zombie->moveZombie(deltaTime);
        zombie->setAnimation();

        zombie = &DancingZombie;
        zombie->moveZombie(deltaTime);
        zombie->setAnimation();
    }
}
void Level1State::Draw(sf::RenderWindow& window)
{
	window.draw(background);
    renderPlantFactory(window);
    renderZombies(window);
    renderUI(window);
	window.display();
	window.clear();
}