#ifndef TEXT_H
#define TEXT_H

#include "../Utils/CommonVariable.h"
#include "../Utils/Vector.h"

class Text
{
private:
    SDL_Color textColor{85, 85, 85, 255};
    Vector pos;
    double scale;

    SDL_Texture *texture;
    SDL_Rect *rect;

public:
    TTF_Font *font = TTF_OpenFont("res/fonts/PressStart2P-Regular.ttf", 24);

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