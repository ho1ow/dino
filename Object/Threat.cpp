#include "Threat.h"

Threat::Threat()
{
    MaxCactus = 1;
    MaxPtero = 0;
}
Threat::~Threat()
{
    removeAll();
}

void Threat::initCactus()
{
    if (allCactus.empty())
    {
        allCactus.emplace_back(std::make_unique<Cactus>(sheet, 1.5));
    }
    else
    {
        bool validPos = false;
        while (!validPos)
        {
            auto tmpCactus = std::make_unique<Cactus>(sheet, 1.5);
            validPos = true;
            for (const auto &cactus : allCactus)
            {
                if (Vector::distance(allCactus.back()->getPos(), tmpCactus->getPos()) < SCREEN_WIDTH / 2)
                {
                    validPos = false;
                    break;
                }
            }
            if (validPos)
            {
                allCactus.push_back(std::move(tmpCactus));
            }
        }
    }
}

void Threat::initPtero()
{
    allPtero.emplace_back(std::make_unique<Ptero>(sheet, 1.5));
}

void Threat::update()
{

    removeOffScreen();
    if (allCactus.size() < MaxCactus)
    {
        initCactus();
    }
    if (allPtero.size() < MaxPtero)
    {
        initPtero();
    }
    for (const auto &threat : allCactus)
    {
        threat->update();
    }
    for (const auto &threat : allPtero)
    {
        threat->update();
    }
}
void Threat::render(SDL_Renderer *renderer)
{
    for (const auto &threat : allCactus)
    {
        threat->render(renderer, threat->getRect());
    }
    for (const auto &threat : allPtero)
    {
        threat->render(renderer, threat->getRect());
    }
}
void Threat::reset()
{
    removeAll();
    MaxCactus = 1;
    MaxPtero = 0;
}

void Threat::removeAll()
{
    allCactus.clear();
    allPtero.clear();
}
void Threat::removeOffScreen()
{
    allCactus.erase(std::remove_if(allCactus.begin(), allCactus.end(),
                                   [](const auto &threat)
                                   { return threat->offScreen(threat->getPos()); }),
                    allCactus.end());
    allPtero.erase(std::remove_if(allPtero.begin(), allPtero.end(),
                                  [](const auto &threat)
                                  { return threat->offScreen(threat->getPos()); }),
                   allPtero.end());
}
bool Threat::isCollide(SDL_Rect dinohitbox)
{
    for (const auto &threat : allCactus)
    {
        if (SDL_HasIntersection(&(threat->hitBox), &dinohitbox) == SDL_TRUE)
        {
            return true;
        }
    }
    for (const auto &threat : allPtero)
    {
        if (SDL_HasIntersection(&(threat->hitBox), &dinohitbox) == SDL_TRUE)
        {
            return true;
        }
    }
    return false;
}

int Threat::getNum()
{
    return allCactus.size() + allPtero.size();
}
int Threat::getCactusNum()
{
    return allCactus.size();
}
int Threat::getPteroNum()
{
    return allPtero.size();
}
void Threat::increaseCactus()
{
    MaxCactus++;
}
void Threat::increasePtero()
{
    MaxPtero++;
}
void Threat::setDefault()
{
    MaxCactus = 0;
    MaxPtero = 0;
}