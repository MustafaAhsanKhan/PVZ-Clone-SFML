#include <SFML/Graphics.hpp>
#include <ctime>
using namespace sf;
using namespace std;

struct coordinats {
    int x;
    int y;
};

// Drawing the map
void createMap(RenderWindow& window, Texture& mapTexture) {
    // Drawing a map
    Sprite s_map;
    s_map.setTexture(mapTexture);

    // Scale the sprite to fit the window size
    float scaleX = static_cast<float>(window.getSize().x) / s_map.getLocalBounds().width;
    float scaleY = static_cast<float>(window.getSize().y) / s_map.getLocalBounds().height;
    s_map.setScale(scaleX, scaleY);

    window.draw(s_map);
}

int main() {
    RenderWindow window(VideoMode(1280, 720), "Plants Vs Zombies");

    // Load the map texture
    Texture mapTexture;
    if (!mapTexture.loadFromFile("C:/Users/optay/OneDrive/Uni/Semester 2/OOP/OOP_PROJECT/starter_files/Images/grid.png")) {
        return 1;
    }

    // Game icon
    Image icon;
    if (!icon.loadFromFile("C:/Users/optay/OneDrive/Uni/Semester 2/OOP/OOP_PROJECT/PVZ_Textures/icon.png")) {
        return 1;
    }
    window.setIcon(32, 32, icon.getPixelsPtr());
    
    ///////////////////////////////////////

    // Game field (5*9)
    // Point 137*79 - leftmost point
    // length 41; width 53
    const int ROWS = 5;
    const int COLS = 9;

    bool FIELD_GAME_STATUS[ROWS][COLS];

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            FIELD_GAME_STATUS[i][j] = true;
        }
    }

    Clock timeMoney;
    Clock clock;

    while (window.isOpen()) {
        float time = clock.getElapsedTime().asMicroseconds();
        float moneyTime = timeMoney.getElapsedTime().asSeconds();
        clock.restart();
        time = time / 800;

        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        // Create a background
        createMap(window, mapTexture);

        window.display();
    }

    return 0;
}
