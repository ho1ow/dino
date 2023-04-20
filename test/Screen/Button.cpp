#include "Button.h"

Button::Button(const char *path, const double scale) : Texture(path, scale)
{
    // crect = &rect;
}
void Button::setPos(Vector pos)
{
    this->pos = pos;
}
void Button::setRect(SDL_Rect *rect)
{
    crect = rect;
}

void Button::render(SDL_Renderer *renderer_, SDL_Rect *rect)
{
    renderWithPosAndScale(renderer, crect, pos, scale);
}
void Button::setScrRectX(int x)
{
    crect->x -= x;
}
void Button::update()
{
    setScrRectX(33);
}
