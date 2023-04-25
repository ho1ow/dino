#include "Threat.h"

Threat::Threat()
{
    initCactus();
    initPtero();
}
Threat::~Threat()
{
    remove();
}

void Threat::initCactus()
{
    allCactus.push_back(new Cactus(sheet, 1.5));
}
void Threat::initPtero()
{
    allPtero.push_back(new Ptero(sheet, 1.5));
}
void Threat::update()
{
    for (auto threat : allCactus)
    {
        threat->update();
    }
    for (auto threat : allPtero)
    {
        threat->update();
    }
}
void Threat::render(SDL_Renderer *renderer)
{
    for (auto threat : allCactus)
    {
        threat->render(renderer, threat->getRect());
    }
    for (auto threat : allPtero)
    {
        threat->render(renderer, threat->getRect());
    }
}
void Threat::reset()
{
    remove();
    initCactus();
    initPtero();
}
void Threat::remove()
{
    for (auto cactus : allCactus)
    {
        delete cactus;
    }
    allCactus.clear();

    for (auto ptero : allPtero)
    {
        delete ptero;
    }
    allPtero.clear();
}
bool Threat::isCollide(SDL_Rect dinohitbox)
{
    for (auto threat : allCactus)
    {
        if (SDL_HasIntersection(&(threat->hitBox), &dinohitbox) == SDL_TRUE)
        {
            return true;
        }
    }
    for (auto threat : allPtero)
    {
        if (SDL_HasIntersection(&(threat->hitBox), &dinohitbox) == SDL_TRUE)
        {
            return true;
        }
    }
    return false;
}
void Threat::upLevel()
{
    initCactus();
    // std::cerr << "check number of cactus: " << allCactus.size() << std::endl;
}