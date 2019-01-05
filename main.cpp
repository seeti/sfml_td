#include "classes/Game.hpp"

Game *mainGame = nullptr;

int main() {

    std::cout << "Iniciando seetiEngine" << std::endl;

    mainGame = new Game();
    mainGame->init(640, 480, "titulillo");

    mainGame->setVerticalSync(true);

    while (mainGame->running())
    {
        mainGame->handleEvents();
        mainGame->update();
        mainGame->render();
    }

    mainGame->clear();

    return 0;
}