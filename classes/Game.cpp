#include "Game.hpp"
#include "GameClock.hpp"
#include "Ball.hpp"
#include "Square.hpp"
#include "Button.hpp"

GameClock *gameClock = nullptr;
Button *boton = nullptr;

Game::Game()
{
    drawables = new Drawables();
    imageManager = new ImageManager();
}

Game::~Game()
{}

void Game::init(int width, int height, sf::String title)
{
    windowTitle = title;

    gameClock = new GameClock();

    videoMode = sf::VideoMode(width, height, (sf::Style::Resize | sf::Style::Close));
    renderWindow.create(videoMode, windowTitle);

    if (renderWindow.isOpen()) isRunning = true;

    std::cout << "drawables count before: " << drawables->drawablesCount() << std::endl;

    boton = new Button();
    boton->setPosition(200.f, 200.f);

    drawables->addDrawable("boton1", boton);

    std::cout << "drawables count after: " << drawables->drawablesCount() << std::endl;
}

void Game::handleEvents()
{
    sf::Event event;
    while ( renderWindow.pollEvent(event) )
    {   
        switch (event.type)
        {
            case sf::Event::Closed:
                isRunning = false;
                break;

            case sf::Event::KeyPressed:
                keyPressed(event.key.code);
                break;

            case sf::Event::KeyReleased:
                break;

            default:
                break;
        }
    }
}

void Game::update()
{
    gameClock->handleClock();

    while(gameClock->getAccumTime() >= gameClock->deltaTime)
    {
        this->update(gameClock->deltaTime);
        gameClock->setAccumTime(gameClock->getAccumTime() - gameClock->deltaTime);
    }
}

void Game::update(float dt)
{   
    boton->update(renderWindow);
}

void Game::render()
{
    // Limpiar pantalla
    renderWindow.clear();

    // Interpolacion
    const float interp = gameClock->getAccumTime() / gameClock->deltaTime;

    // Dibujar en el buffer
    drawables->draw(renderWindow, interp);

    // Volcar el buffer
    renderWindow.display();
}

void Game::clear()
{
    delete this;
    renderWindow.close();
    std::cout << "Clear done" << std::endl;
}

void Game::setVerticalSync(bool val)
{
    renderWindow.setVerticalSyncEnabled(val);
}

void Game::keyPressed(sf::Keyboard::Key key)
{
    std::cout << "Key pressed: " << key << std::endl;

    switch (key)
    {        
        case sf::Keyboard::Escape:
            isRunning = false;
            break;

        case sf::Keyboard::Return:
            
            // Alt + Enter = Fullscreen mode
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt)) {

                std::cout << "Toggling FullScreen mode" << std::endl;

                if (isFullscreen)
                {
                    renderWindow.create(videoMode, windowTitle, (sf::Style::Resize | sf::Style::Close));
                    isFullscreen = false;
                }
                else
                {
                    renderWindow.create(videoMode, windowTitle, sf::Style::Fullscreen);
                    isFullscreen = true;
                }
            }
            break;

        default:
            break;
    }
}