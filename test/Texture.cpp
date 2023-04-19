#include "Texture.h"

Texture::Texture(const char *path)
{
    cTexture = IMG_LoadTexture(renderer, path);
    scale = 1;
}
Texture::Texture(const char *path, const double scale_)
{
    cTexture = IMG_LoadTexture(renderer, path);
    scale = scale_;
}

Texture::~Texture()
{
}
SDL_Texture *Texture::getTexture()
{
    return cTexture;
}
SDL_Rect *Texture::getRect()
{
    return crect;
}
int Texture::getRectWidth()
{
    
    return static_cast<int>(crect->w * scale);
}
int Texture::getRectHeight()
{
    return static_cast<int>(crect->h * scale);
}
int Texture::getRectX()
{
    return crect->x;
}
int Texture::getRectY()
{
    return crect->y;
}

void Texture::renderScroll(SDL_Renderer *renderer_, SDL_Rect *rect)
{
    SDL_Rect destRect = {x_, SCREEN_HEIGHT - rect->h-20, rect->w, rect->h};
    SDL_RenderCopy(renderer_, cTexture, rect, &destRect);
    destRect = {x_ - rect->w, SCREEN_HEIGHT - rect->h-20, rect->w, rect->h};
    SDL_RenderCopy(renderer_, cTexture, rect, &destRect);
}

void Texture::renderWithPos(SDL_Renderer *renderer_, SDL_Rect *rect, Vector2 pos)
{
    SDL_Rect destRect = {pos.x, pos.y, rect->w, rect->h};
    SDL_RenderCopy(renderer_, cTexture, rect, &destRect);
}

void Texture::renderWithPosAndScale(SDL_Renderer *renderer_, SDL_Rect *rect, Vector2 pos, double scale)
{
    SDL_Rect destRect = {pos.x, pos.y, static_cast<int>(rect->w * scale), static_cast<int>(rect->h * scale)};
    SDL_RenderCopy(renderer_, cTexture, rect, &destRect);
}

void Texture::update(SDL_Rect *rect)
{
    x_ -= speed_;
    if (x_ <= 0)
    {
        x_ = rect->w;
    }
}
bool Texture::offScreen(Vector2 pos)
{
    if (pos.x + getRectWidth() < 0 || pos.x - getRectWidth() > SCREEN_WIDTH || pos.y + getRectHeight() < 0 || pos.y - getRectHeight() > SCREEN_HEIGHT)
    {
        return true;
    }
    return false;
}

