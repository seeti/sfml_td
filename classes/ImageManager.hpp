#ifndef __IMAGEMANAGER_HPP
#define __IMAGEMANAGER_HPP

#include <SFML/Graphics.hpp>
#include <map>
#include <iostream>

class ImageManager {

    public:
        ImageManager();

        sf::Sprite getSprite(std::string);

    private:
        std::map<sf::String, sf::Texture> textures;
        std::map<sf::String, sf::Texture>::iterator texture_it;

        const sf::Texture& getTexture(std::string);
};

#endif // __IMAGEMANAGER_HPP