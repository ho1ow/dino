#ifndef THREAT_H
#define THREAT_H

#include "Cactus.h"
#include "Ptero.h"

class Threat
{
private:
    std::list<Cactus *> allCactus;
    std::list<Ptero *> allPtero;

    int cactusNum = allCactus.size();
    int pteroNum = allPtero.size();

public:
    Threat();
    ~Threat();

    //update pos, type, hit box and make object move 
    void update();

    void initCactus();
    void initPtero();
    void render(SDL_Renderer *renderer);
    void reset();
    void remove();
    void upLevel();
    bool isCollide(SDL_Rect dinohitbox);
};

#endif