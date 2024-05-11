#include "AssetManager.h"

bool AssetManager::loadTexture(int index, const string& filename)  // index - index of the texture in the array
{
    if (index < 0 || index >= MAX_TEXTURES)
    {
        cout << "Invalid texture index!" << endl;
        return false;
    }

    if (loaded[index])  // Check if the texture is already loaded
    {
        cout << "Texture at index " << index << " is already loaded!" << endl;
        return false;
    }

    if (!textures[index].loadFromFile(filename))  // Unable to load the texture from file
    {
        cout << "Failed to load texture from file: " << filename << endl;
        return false;
    }

    textures[index].loadFromFile(filename);  // Load the texture from file into the array
    loaded[index] = true;
    return true;
}

// Retrieve texture by index
sf::Texture& AssetManager::getTexture(int index)
{

    if (index < 0 || index >= MAX_TEXTURES || !loaded[index])
    {
        cout << "Texture at index " << index << " not found or not loaded!" << endl;

        return textures[0];  // Returning a dummy texture
    }
    return textures[index];
}