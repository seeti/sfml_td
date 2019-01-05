#include "Ball.hpp"

Ball::Ball()
{
    m_shape.setRadius(50.f);
    m_shape.setFillColor(sf::Color::Yellow);

    isMoving = false;
    direction = Direction::None;

    //m_shape.setOrigin(this->getOrigin().x, this->getOrigin().y);
    //m_shape.setPosition(this->getPosition().x, this->getPosition().y);
    //getGlobalBounds();
}

sf::FloatRect Ball::getGlobalBounds()
{
    return getTransform().transformRect( m_shape.getLocalBounds() );
}

void Ball::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // You can draw other high-level objects
    states.transform *= getTransform();
    target.draw(m_shape, states);
}