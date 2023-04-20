#ifndef BUTTON_H
#define BUTTON_H

#include "../Texture.h"

class Button : public Texture
{
private:
public:
    Button(const char *path, const double scale);
    ~Button();
    Vector pos{10,10};

    void setPos(Vector pos);
    void setRect(SDL_Rect *rect);
    void setScrRectX(int x);

    void isHovered();
    void isClicked();

    void update();
    void render(SDL_Renderer *renderer_, SDL_Rect *rect);
};

#endif