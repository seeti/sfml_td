#include "Button.hpp"

Button::Button()
{
    boton_style = Style::Rounded;
    this->init();
}

Button::Button(Style _style)
{
    boton_style = _style;
    this->init();
}

void Button::update(sf::RenderWindow &window)
{
    if ( mouseHover(window) )
    {
        if (boton_state == State::Hover && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            boton_sprite = imageManager.getSprite(filePath + "click");
            boton_state = State::Pressed;
            std::cout << "mouse click" << std::endl;
        }
        
        if ((boton_state != State::Hover) && (boton_state != State::Pressed))
        {
            boton_sprite = imageManager.getSprite(filePath + "hover");
            boton_state = State::Hover;
            std::cout << "mouse hover" << std::endl;
        }
    }
    else
    {
        if (boton_state != State::Idle)
        {
            boton_sprite = imageManager.getSprite(filePath + "idle");
            boton_state = State::Idle;
            std::cout << "mouse out" << std::endl;
        }
    }
}

void Button::init()
{
    switch (boton_style)
    {
        case Style::Rounded:
            filePath = "boton_";
            break;
        case Style::Square:
            filePath = "boton_square_";
            break;
        default:
            filePath = "boton_";
            break;
    }
    
    boton_sprite = imageManager.getSprite(filePath + "idle");
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