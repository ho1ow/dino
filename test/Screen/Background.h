#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "../Object/Cloud.h"
#include "../Object/Road.h"

class Background
{
private:
    Cloud *cloud;
    Road *road;

    SDL_Color night = {0, 0, 0, 255};
    SDL_Color day = {255, 255, 255, 255};
    bool isNight = false;
    bool isDay = true;
    const int change = 5;

public:
    Background();
    ~Background();

    static SDL_Color color;

    void update();
    void renderCloudAndRoad(SDL_Renderer *renderer);

    void setBgColor(SDL_Color color);
    void setNight(SDL_Color color);
    void setDay(SDL_Color color);


    void renderBg(SDL_Renderer *renderer);
};

#endif