#include "Timer.h"

uint64_t Timer::lastTime = 0;
uint64_t Timer::delta = SDL_GetTicks64() - lastTime;
bool Timer::isPause = false;

void Timer::reset()
{
    lastTime = SDL_GetTicks64();
}

uint64_t Timer::deltaTime()
{
    if (isPause)
        return 0;

    return delta;
}

void Timer::update()
{
    delta = SDL_GetTicks64() - lastTime;
}

float Timer::deltaTimeInSecond()
{
    return (deltaTime() / TO_SECOND);
}

void Timer::paused()
{
    isPause = true;
}

void Timer::resume()
{
    isPause = false;
}