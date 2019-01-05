#include "ImageManager.hpp"

ImageManager::ImageManager()
{

}

sf::Sprite ImageManager::getSprite(std::string spriteName)
{
    sf::Sprite sprite;

    sprite.setTexture(getTexture(spriteName));

    return sprite;
}

const sf::Texture& ImageManager::getTexture(std::string fileName)
{
    texture_it = textures.find(fileName);
    if ( texture_it != textures.end() )
    {
        std::cout << "Image (" << fileName << ") already exists." << std::endl;
        return textures[fileName];
    }
    else
    {
        sf::Texture img;
        if ( img.loadFromFile("sprites/" + fileName + ".png") )
        {
            textures[fileName] = img;
            std::cout << "Image (" << fileName << ") added." << std::endl;
        }

        return textures[fileName];
    }
}