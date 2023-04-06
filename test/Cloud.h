#ifndef DINO_CLOUD_H
#define DINO_CLOUD_H

#include "commonVar.h"

class Cloud
{
protected:
    SDL_Texture *ctexture;
    SDL_Rect crect;

public:
    Cloud();
    ~Cloud();
};

#endif