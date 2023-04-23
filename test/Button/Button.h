#ifndef BUTTON_H
#define BUTTON_H

#include "../Utils/Texture.h"

class Button : public Texture
{
private:
    Vector pos{10, 10};

public:
    Button(const char *path, SDL_Rect *rect, const double scale);
    ~Button();

    bool isInside();

    void setPos(Vector pos);
    Vector getPos(Vector pos);

    void setRect(SDL_Rect *rect);

    void hover();
    bool isLeftClick();
    void click();
    void afterClick();

    void render(SDL_Renderer *renderer_, SDL_Rect *rect);
};

#endif