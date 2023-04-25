#ifndef THREAT_H
#define THREAT_H

#include "Cactus.h"
#include "Ptero.h"
#include <memory>
#include <algorithm>
class Threat
{
private:
    std::vector<std::unique_ptr<Cactus>> allCactus;
    std::vector<std::unique_ptr<Ptero>> allPtero;

    int MinCactusDist = 1500;
    int MinPteroDist = 100;

    int MaxCactus;
    int MaxPtero;

public:
    Threat();
    ~Threat();

    // update pos, type, hit box and make object move

    void initCactus();
    void initPtero();

    void render(SDL_Renderer *renderer);
    void update();
    void reset();
    bool isCollide(SDL_Rect dinohitbox);

    int getNum();
    int getCactusNum();
    int getPteroNum();

    void increaseCactus();
    void increasePtero();

    void setDefault();

    void removeOffScreen();
    void removeAll();
    void remove();
    void printPos();
};

#endif