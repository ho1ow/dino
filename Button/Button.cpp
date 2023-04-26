#include "Button.h"

Button::Button(const char *path, SDL_Rect *rect, const double scale) : Texture(path, scale)
{
    crect = rect;
}
void Button::setPos(Vector pos)
{
    this->pos = pos;
}
Vector Button::getPos(Vector pos)
{
    return pos;
}
void Button::setRect(SDL_Rect *rect)
{
    crect = rect;
}

void Button::render(SDL_Renderer *renderer_, SDL_Rect *rect)
{
    renderWithPosAndScale(renderer, crect, pos, scale);
}
bool Button::isInside()
{
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);
    if (mouseX >= pos.x && mouseX <= pos.x + crect->w * scale &&
        mouseY >= pos.y && mouseY <= pos.y + crect->h * scale)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Button::hover()
{
    if (isInside())
    {
        SDL_SetTextureColorMod(cTexture, 150, 150, 150);
    }
    else
    {
        SDL_SetTextureColorMod(cTexture, 255, 255, 255);
    }
}
void Button::afterClick()
{
    SDL_SetTextureColorMod(cTexture, 255, 255, 255);
}
