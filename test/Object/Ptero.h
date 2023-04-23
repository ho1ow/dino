#ifndef PTERO_H
#define PTERO_H

#include "../Utils/Texture.h"

class Ptero : public Texture
{
private:
    static const int PTERO_VEL = -15;
    const int padding = 12;

    struct
    {
        SDL_Rect rect{260, 2, 92, 82};
    } ptero;
    SDL_Rect currentClip = ptero.rect;

public:
    Ptero(const char *path, const double scale);
    ~Ptero(){};

    SDL_Rect hitBox;
    Vector PteroPos;
    Vector ranPteroPos();
    void getPteroPos();

    void getPteroFrame();

    void render(SDL_Renderer *renderer, SDL_Rect *rect);
    void update();
    void updateHitBox();

    void reset();
};

#endif