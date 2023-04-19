#ifndef TEXTURE_H
#define TEXTURE_H

#include "commonVar.h"
#include "Utils/Vector.h"
#include "Utils/Random.h"

class Texture
{
protected:
    SDL_Texture *cTexture;
    SDL_Rect *crect;
    double scale;
    SDL_Renderer *renderer_;
    int x_;
    double speed_;

public:
    SDL_Texture *getTexture();
    SDL_Rect *getRect();

    int getRectWidth();
    int getRectHeight();
    int getRectX();
    int getRectY();

    Texture(const char *path);
    Texture(const char *path, const double scale_);
    ~Texture();

    void renderScroll(SDL_Renderer *renderer_, SDL_Rect *rect);
    void renderWithPos(SDL_Renderer *renderer_, SDL_Rect *rect, Vector2 pos);
    void renderWithPosAndScale(SDL_Renderer *renderer_, SDL_Rect *rect, Vector2 pos, double scale);

    void update(SDL_Rect *rect);

    void set_speed(double speed) { speed_ = speed; }
    double get_speed() { return speed_; }

    bool offScreen(Vector2 pos);

};

#endif