#ifndef ROAD_H
#define ROAD_H

#include "../Utils/Texture.h"

class Road : public Texture
{
private:
    SDL_Rect road={2, 100, 2402, 30};
public:
    Road(const char *path) : Texture(path)
    {
        crect = &road;
    }
    ~Road(){};
    
    void reset();
};

#endif