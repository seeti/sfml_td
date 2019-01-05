#ifndef __BALL_HPP
#define __BALL_HPP

#include <SFML/Graphics.hpp>
#include "Drawables.hpp"

enum class Direction { None, Up, Down, Left, Right };

class Ball : public DrawableAndTransformable {

    public:
        Ball();

        sf::CircleShape m_shape;
        bool isMoving;
        Direction direction;

        sf::FloatRect getGlobalBounds();

    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif // __BALL_HPP