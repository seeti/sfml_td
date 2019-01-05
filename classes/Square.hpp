#ifndef __SQUARE_HPP
#define __SQUARE_HPP

#include <SFML/Graphics.hpp>
#include "Drawables.hpp"

class Square : public DrawableAndTransformable {

    public:
        Square();

        sf::RectangleShape m_shape;
        bool isMoving;

        sf::FloatRect getGlobalBounds();

    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif // __SQUARE_HPP