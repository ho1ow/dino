#include "Road.h"

void Road::reset()
{
    pos.x = 0;
}
void Road::update()
{
    pos.x -= 4;
    if (pos.x < 0)
    {
        pos.x = crect->w;
    }
}
void Road::render(SDL_Renderer *renderer_, SDL_Rect *rect)
{
    Texture::renderWithPos(renderer_, crect, pos);
    Texture::renderWithPos(renderer_, crect, {pos.x - crect->w, pos.y});
}
// void Texture::renderScroll(SDL_Renderer *renderer_, SDL_Rect *rect)
// {
//     SDL_Rect destRect = {x_, SCREEN_HEIGHT - rect->h - 20, rect->w, rect->h};
//     SDL_RenderCopy(renderer_, cTexture, rect, &destRect);
//     destRect = {x_ - rect->w, SCREEN_HEIGHT - rect->h - 20, rect->w, rect->h};
//     SDL_RenderCopy(renderer_, cTexture, rect, &destRect);
// }