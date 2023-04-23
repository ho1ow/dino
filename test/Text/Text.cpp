#include "Text.h"

Text::Text(const char *text, SDL_Rect *rect, Vector pos, double scale)
{
    this->pos = pos;
    this->scale = scale;
    this->rect = rect;
    createTexture(text);
}
void Text::createTexture(const char *text)
{
    if (font == nullptr)
    {
        std::cerr << "Error loading font: " << TTF_GetError() << std::endl;
        exit(0);
    }

    if (text == nullptr)
    {
        std::cerr << "Error: text is null!" << std::endl;
        exit(0);
    }

    SDL_Surface *surface = TTF_RenderText_Blended(font, text, textColor);
    if (surface == nullptr)
    {
        std::cerr << "Error creating surface: " << TTF_GetError() << std::endl;
        exit(0);
    }

    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    if (texture == nullptr)
    {
        std::cerr << "Error creating texture: " << SDL_GetError() << std::endl;
        exit(0);
    }
}
void Text::updateText(const char *text)
{
    createTexture(text);
}
void Text::setTextPos(Vector pos)
{
    this->pos = pos;
}
SDL_Rect *Text::getRect()
{
    return this->rect;
}
Vector Text::getPos()
{
    return this->pos;
}
void Text::render()
{
    SDL_Rect destRect = {pos.x, pos.y, static_cast<int>(rect->w * scale), static_cast<int>(rect->h * scale)};
    SDL_RenderCopy(renderer, texture, NULL, &destRect);
}
