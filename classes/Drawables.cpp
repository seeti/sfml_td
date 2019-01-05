#include "Drawables.hpp"

Drawables::Drawables()
{
    //drawablesList = new std::map<sf::String, sf::Drawable>();
}

void Drawables::addDrawable(sf::String name, DrawableAndTransformable *drawablez)
{
    //drawablesList.emplace(name, drawablez);
    drawablesList[name] = drawablez;
}

void Drawables::draw(sf::RenderTarget& target, float interp)
{

    // Dibujar en el buffer
    for (auto itt = this->drawablesBegin(); itt != this->drawablesEnd(); itt++)
    {
        // TODO: Interpolation

        target.draw(*itt->second);
    }
}

/*
DrawableAndTransformable Drawables::getDrawableByString(sf::String name)
{
    return drawablesList.find(name);
}
*/