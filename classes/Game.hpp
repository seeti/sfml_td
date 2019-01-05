#ifndef __GAME_HPP
#define __GAME_HPP

#include <SFML/Graphics.hpp>
#include "Drawables.hpp"
#include "ImageManager.hpp"
#include <iostream>

class Game {

    public:
        Game();
        ~Game();

        void init(int width, int height, sf::String title);
        void handleEvents();
        void update();
        void render();
        void clear();

        bool running() { return isRunning; }
        sf::String getWindowTitle() { return windowTitle; }
        void setVerticalSync(bool);
    
    private:
        void keyPressed(sf::Keyboard::Key);
        void ballMovement(sf::Keyboard::Key);
        void update(float dt);

        sf::RenderWindow renderWindow;
        sf::VideoMode videoMode;
        sf::CircleShape shape;
        bool isRunning;
        bool isFullscreen = false;
        sf::String windowTitle;
        int count = 0;

        Drawables *drawables;
        ImageManager *imageManager;
};

#endif // __GAME_HPP