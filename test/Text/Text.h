#ifndef TEXT_H
#define TEXT_H

#include "../Utils/CommonVariable.h"
#include "../Utils/Vector.h"

#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>
#include <iostream>
class Text
{
private:
    SDL_Color textColor{85, 85, 85, 255};
    Vector pos;
    double scale;

    SDL_Texture *texture;
    SDL_Rect *rect;

public:
    
    Text(const char *text, SDL_Rect *rect, Vector pos, double scale = 1);
    ~Text(){};

    void createTexture(const char *text);

    void updateText(const char *text);

    SDL_Rect *getRect();
    Vector getPos();

    void setTextPos(Vector pos);
    void setRect(SDL_Rect *rect);

    void update();
    void render();
};
#endif
