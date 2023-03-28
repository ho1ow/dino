#ifndef MAINOBJECT_H
#define MAINOBJECT_H
#include "commonVar.h"

class player
{
protected:
    SDL_Texture *ctexture;
    SDL_Rect crect;

public:
    player();
    ~player();
    SDL_Texture *get_text() const { return ctexture; }
    void load_sprite(SDL_Renderer *renderer, const char *file);
    void render_sprite(SDL_Renderer *renderer, const double &scale);
    void set_rect_cordinate(const int &x, const int &y);
    void set_rect_cordinate_width_and_height(const int &x, const int &y, const int &width, const int &height);
    void set_rect_width_and_height(const int &width, const int &height);
    void handlingMovement(SDL_Event &event);
    SDL_Rect get_rect() const;
    SDL_Rect get_rect_width_height_with_scale(const double &scale) const;
};

#endif