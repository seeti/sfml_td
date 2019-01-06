#include "Button.hpp"

Button::Button()
{
    this->init();
}

Button::Button(float x, float y)
{
    this->init();
    this->setPosition(x, y);
}

Button::Button(sf::Vector2f pos)
{
    this->init();
    this->setPosition(pos);
}

void Button::update(sf::RenderWindow &window)
{
    if ( mouseHover(window) )
    {
        if (boton_state == State::Hover && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            boton_sprite = imageManager.getSprite("boton_click");
            boton_state = State::Pressed;
            std::cout << "mouse click" << std::endl;
        }
        
        if ((boton_state != State::Hover) && (boton_state != State::Pressed))
        {
            boton_sprite = imageManager.getSprite("boton_hover");
            boton_state = State::Hover;
            std::cout << "mouse hover" << std::endl;
        }
    }
    else
    {
        if (boton_state != State::Idle)
        {
            boton_sprite = imageManager.getSprite("boton_idle");
            boton_state = State::Idle;
            std::cout << "mouse out" << std::endl;
        }
    }
}

void Button::init(void)
{
    boton_sprite = imageManager.getSprite("boton_idle");
    boton_state = State::Idle;
}

bool Button::mouseHover(sf::RenderWindow &window)
{
    return getGlobalBounds().contains( (sf::Vector2f)sf::Mouse::getPosition(window) ) ? true : false;
}

sf::FloatRect Button::getGlobalBounds(void)
{
    return getTransform().transformRect( boton_sprite.getLocalBounds() );
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{   
    // You can draw other high-level objects
    states.transform *= getTransform();
    target.draw(boton_sprite, states);
}