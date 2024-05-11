#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
using namespace std;


class AssetManager
{
private:
    static const int MAX_TEXTURES = 50;  // Maximum number of textures that can be stored
    sf::Texture textures[MAX_TEXTURES];  // Array of textures
    bool loaded[MAX_TEXTURES] = { false };  // Array of flags to indicate if a texture is loaded

public:
    // Load texture from file and store it
    bool loadTexture(int index, const string& filename);  // index - index of the texture in the array

    // Retrieve texture by index
    sf::Texture& getTexture(int index);
};