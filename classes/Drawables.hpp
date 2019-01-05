#ifndef __DRAWABLES_HPP
#define __DRAWABLES_HPP

#include <SFML/Graphics.hpp>
#include <map>
#include <iterator>

class DrawableAndTransformable: public sf::Drawable, public sf::Transformable {};

class Drawables {

    public:
        Drawables();
        ~Drawables();

        void addDrawable(sf::String name, DrawableAndTransformable *drawablez);
        //DrawableAndTransformable getDrawableByString(sf::String name);

        int drawablesCount() { return drawablesList.size(); }
        std::map<sf::String, DrawableAndTransformable*>::iterator drawablesBegin() { return drawablesList.begin(); }
        std::map<sf::String, DrawableAndTransformable*>::iterator drawablesEnd() { return drawablesList.end(); }
        std::map<sf::String, DrawableAndTransformable*>::iterator getDrawablesIterator() { return drawableIterator; };

        void draw(sf::RenderTarget& target, float interp);

    private:
        
        std::map<sf::String, DrawableAndTransformable*> drawablesList;
        std::map<sf::String, DrawableAndTransformable*>::iterator drawableIterator;
};

#endif // __DRAWABLES_HPP