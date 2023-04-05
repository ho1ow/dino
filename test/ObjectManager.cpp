#include "ObjectManager.h"

Object::Object()
{
    crect.x = 0;
    crect.y = 0;
    
}

Object::~Object()
{
}
void Object::load_sprite(SDL_Renderer *renderer, const char *file)
{
}

void Object::renderWithScale(SDL_Renderer *renderer, const double &scale)
{
    crect.w = static_cast<int>(crect.w * scale);
    crect.h = static_cast<int>(crect.h * scale);
    SDL_Rect destRect = {crect.x, crect.y, crect.w, crect.h};

    // Render the current sprite
    SDL_RenderCopy(renderer, ctexture, nullptr, &destRect);
}

void Object::set_rect_cordinate(const int &x, const int &y)
{
    crect.x = x;
    crect.y = y;
}
void Object::set_rect_cordinate_width_and_height(const int &x, const int &y, const int &width, const int &height)
{
    crect.x = x;
    crect.y = y;
    crect.w = width;
    crect.h = height;
}
void Object::set_rect_width_and_height(const int &width, const int &height)
{
    crect.w = width;
    crect.h = height;
}

void Object::handlingMovement(SDL_Event &event)
{
}

SDL_Rect Object::get_rect() const
{
    return crect;
}
SDL_Rect Object::get_rect_width_height_with_scale(const double &scale) const
{
    SDL_Rect rect = {crect.x, crect.y, static_cast<int>(crect.w * scale), static_cast<int>(crect.h * scale)};
    return rect;
}