#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "../Object/Cloud.h"
#include "../Object/Road.h"
#include "../Texture.h"
#include "Button.h"
class Background
{
private:

    Cloud *cloud;
    Road *road;

    Texture *gameover;
    Texture *restartButton;

    Button *pause;

    SDL_Color color;
    SDL_Color night = {0, 0, 0, 255};
    SDL_Color day = {255, 255, 255, 255};
    bool isNight = false;
    const int change = 5;

public:
    Background();
    ~Background();

    void update();
    void renderCloudAndRoad(SDL_Renderer *renderer);

    void setIsNight();
    void setIsDay();
    void setNight();
    void setDay();

    void renderBg(SDL_Renderer *renderer);
    void renderGameOver(SDL_Renderer *renderer);
    void bgPause();
    void reset();
};

#endif