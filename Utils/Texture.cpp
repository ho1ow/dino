#include "Texture.h"

Texture::Texture(const char *path)
{
    cTexture = IMG_LoadTexture(renderer, path);
    scale = 1;
}

Texture::Texture(const char *path, const double scale)
{
    cTexture = IMG_LoadTexture(renderer, path);
    this->scale = scale;
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

void Texture::renderWithPos(SDL_Renderer *renderer_, SDL_Rect *rect, Vector pos)
{
    SDL_Rect destRect = {pos.x, pos.y, rect->w, rect->h};
    SDL_RenderCopy(renderer_, cTexture, rect, &destRect);
}

void Texture::renderWithPosAndScale(SDL_Renderer *renderer_, SDL_Rect *rect, Vector pos, double scale)
{
    SDL_Rect destRect = {pos.x, pos.y, static_cast<int>(rect->w * scale), static_cast<int>(rect->h * scale)};
    SDL_RenderCopy(renderer_, cTexture, rect, &destRect);
}

bool Texture::offScreen(Vector pos)
{
    if (pos.x + getRectWidth() < 0 || pos.x - getRectWidth() > SCREEN_WIDTH || pos.y + getRectHeight() < 0 || pos.y - getRectHeight() > SCREEN_HEIGHT)
    {
        return true;
    }
    return false;
}
