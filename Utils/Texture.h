#ifndef TEXTURE_H
#define TEXTURE_H

#include "CommonVariable.h"
#include "Vector.h"
#include "Random.h"

class Texture
{
protected:
    SDL_Texture *cTexture;
    SDL_Rect *crect;
    double scale;
    SDL_Renderer *renderer_;

public:
    SDL_Texture *getTexture();
    
    SDL_Rect *getRect();
    
    int getRectWidth();
    int getRectHeight();

    Texture(const char *path);
    Texture(const char *path, const double scale);
    ~Texture();

    void renderWithPos(SDL_Renderer *renderer_, SDL_Rect *rect, Vector pos);
    void renderWithPosAndScale(SDL_Renderer *renderer_, SDL_Rect *rect, Vector pos, double scale);

    bool offScreen(Vector pos);

};

#endif