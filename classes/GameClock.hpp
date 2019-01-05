#ifndef __GAMECLOCK_HPP
#define __GAMECLOCK_HPP

#include <SFML/System/Clock.hpp>

class GameClock : sf::Clock {

    public:
        GameClock();
        ~GameClock();

        const float deltaTime = 1.0f / 30.f;
        void handleClock();
        float getCurrentTime() { return currentTime; };
        float getAccumTime() { return accumTime; }
        void setAccumTime(float time);

    private:
        float timeNew;
        float timeFrame;
        float currentTime;
        float accumTime;
};

#endif // __GAMECLOCK_HPP