#ifndef TIMER_H
#define TIMER_H

#include <iostream>
#include <SDL2/SDL.h>

class Timer
{

private:
    static uint64_t lastTime;
    static uint64_t delta;
    static bool isPause;

public:
    static constexpr float TO_SECOND = 1000.0f;
    static void reset();
    static void update();
    static uint64_t deltaTime();
    static float deltaTimeInSecond();

    static void paused();
    static void resume();
};

#endif