#ifndef COMMONVARIABLE_H
#define COMMONVARIABLE_H

#include <SDL2/SDL.h>
#include <cmath>
#include <vector>
#include <map>
#include <fstream>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;



extern SDL_Window *window;
extern SDL_Renderer *renderer;
extern SDL_Event event;

extern const char *dinoSprite;

extern bool check_collision_2_rect(const SDL_Rect &a, const SDL_Rect &b);

#endif