#include "GameClock.hpp"

GameClock::GameClock()
{
    currentTime = getElapsedTime().asSeconds();
    accumTime = 0.0f;
}

GameClock::~GameClock()
{}

void GameClock::handleClock()
{
    timeNew = getElapsedTime().asSeconds();
    timeFrame = timeNew - currentTime;

    // Evitar "Spiral of death"
    if (timeFrame > 0.25f) timeFrame = 0.25f;

    currentTime = timeNew;
    accumTime += timeFrame;
}

void GameClock::setAccumTime(float time)
{
    accumTime = time;
}