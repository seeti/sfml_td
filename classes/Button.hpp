#ifndef __BUTTON_HPP
#define __BUTTON_HPP

#include <SFML/Graphics.hpp>
#include "Drawables.hpp"
#include "ImageManager.hpp"

enum class State {Idle, Hover, Pressed};

class Button : public DrawableAndTransformable
{
    public:
        Button();
        Button(float, float);
        Button(sf::Vector2f);

        void update(sf::RenderWindow &window);
        sf::FloatRect getGlobalBounds(void);

    private:
        ImageManager imageManager;
        State boton_state;
        sf::Sprite boton_sprite;

        void init(void);
        bool mouseHover(sf::RenderWindow &window);
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif