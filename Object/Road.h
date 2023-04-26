#ifndef ROAD_H
#define ROAD_H

#include "../Utils/Texture.h"

class Road : public Texture
{
private:
    SDL_Rect road = {2, 100, 2402, 30};
    Vector pos = {0, SCREEN_HEIGHT - road.h - 20};
public:
    Road(const char *path) : Texture(path)
    {
        crect = &road;
    }
    ~Road(){};

    void reset();
    void update();
    void render(SDL_Renderer *renderer_, SDL_Rect *rect);
};

#endif