#ifndef COMMONVARIABLE_H
#define COMMONVARIABLE_H

#include <SDL2/SDL.h>
#include <cmath>
#include <vector>
#include <map>
#include <list>
#include <fstream>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>
#include "Utils/Timer.h"

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
extern const char *sheet;

extern SDL_Window *window;
extern SDL_Renderer *renderer;
extern SDL_Event event;

extern const char *dinoSprite;
struct
{
    struct
    {
        const char *path = "res/buttons/pause.png";
        SDL_Rect rect{35, 2, 33, 33};
        SDL_Rect resume{2,2,33,33};
    } pause;

    struct
    {
        const char *path = "res/buttons/music.png";
        SDL_Rect rect{0, 0, 32, 32};
    } musicSetting;

    struct
    {
        const char *path = "res/buttons/change.png";
        SDL_Rect rect{0, 0, 72, 26};
    } change;

    struct
    {
        const char *path = "res/buttons/exit_arrow.png";
        SDL_Rect rect{0, 0, 32, 32};
    } exit;
} buttons;

extern bool checkCollision(const SDL_Rect &a, const SDL_Rect &b);

#endif