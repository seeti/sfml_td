#include "Square.hpp"

Square::Square()
{
    m_shape.setSize(sf::Vector2f(100,50));
    m_shape.setFillColor(sf::Color::Green);

    isMoving = false;
}

sf::FloatRect Square::getGlobalBounds()
{
    return getTransform().transformRect( m_shape.getLocalBounds() );
}

void Square::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // You can draw other high-level objects
    states.transform *= getTransform();
    target.draw(m_shape, states);
}
