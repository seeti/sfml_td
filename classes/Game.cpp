#include "Game.hpp"
#include "GameClock.hpp"
#include "Ball.hpp"
#include "Square.hpp"

Ball *bola = nullptr;
Square *rect = nullptr;
GameClock *gameClock = nullptr;

sf::Sprite spritez;

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

    bola = new Ball();
    bola->setPosition(350.f, 350.f);

    rect = new Square();
    rect->setPosition(200.f, 200.f);

    drawables->addDrawable("bola4", bola);
    drawables->addDrawable("rect", rect);

    std::cout << "drawables count after: " << drawables->drawablesCount() << std::endl;

    spritez = imageManager->getSprite("boton_idle");
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
                ballMovement(event.key.code);
                break;

            case sf::Event::KeyReleased:
                bola->direction = Direction::None;
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
    if (bola->isMoving)
    {
        float mov = 30.f * dt;

        switch (bola->direction)
        {
            case Direction::Up:
                bola->move(0, -mov);
                std::cout << "Moving UP" << std::endl;
                break;
            case Direction::Down:
                bola->move(0, mov);
                std::cout << "Moving DOWN" << std::endl;
                break;
            case Direction::Left:
                bola->move(-mov, 0);
                std::cout << "Moving LEFT" << std::endl;
                break;
            case Direction::Right:
                bola->move(mov, 0);
                std::cout << "Moving RIGHT" << std::endl;
                break;
        
            default:
                break;
        }
    }

    if ( bola->getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(renderWindow)) )
    {
        std::cout << "mouse in! \n -" << std::endl;
    }

    if ( bola->getGlobalBounds().intersects(rect->getGlobalBounds()))
    {
        std::cout << "intersects! \n -" << std::endl;
    }
}

void Game::render()
{
    // Limpiar pantalla
    renderWindow.clear();

    // Interpolacion
    const float interp = gameClock->getAccumTime() / gameClock->deltaTime;

    // Dibujar en el buffer
    drawables->draw(renderWindow, interp);

    spritez.setPosition(50.f, 50.f);
    renderWindow.draw(spritez);

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

void Game::ballMovement(sf::Keyboard::Key key)
{
    if (key == sf::Keyboard::A) bola->direction = Direction::Left;
    if (key == sf::Keyboard::D) bola->direction = Direction::Right;
    if (key == sf::Keyboard::W) bola->direction = Direction::Up;
    if (key == sf::Keyboard::S) bola->direction = Direction::Down;

    bola->isMoving = true;
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