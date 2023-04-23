#ifndef CACTUS_H
#define CACTUS_H

#include "../Utils/Texture.h"

class Cactus : public Texture
{
private:
    static const int CACTUS_VEL = -10;
    const int padding = 16;

    int cactusHeight;

    SDL_Rect cactus[6] = {
        {446, 2, 34, 70},
        {480, 2, 68, 70},
        {548, 2, 102, 70},
        {652, 2, 50, 100},
        {702, 2, 100, 100},
        {802, 2, 150, 100}};

public:
    Cactus(const char *path, const double scale_);
    ~Cactus(){};
    SDL_Rect hitBox;

    Vector cactusPos;
    Vector ranCactusPos();
    void getCactusPos();

    int ranCactusType();
    void getCactusType();

    void render(SDL_Renderer *renderer, SDL_Rect *rect);
    void update();
    void reset();
};

#endif