#ifndef BUTTON_H
#define BUTTON_H

#include "../Texture.h"

class Button : public Texture
{
    struct
    {
        struct
        {
            char *path = "assets/buttons/play.png";
            SDL_Rect rect{35, 2, 34, 33};
        } pause;

        struct
        {
            char *path = "assets/buttons/music.png";
            SDL_Rect rect{0, 0, 32, 32};
        } musicSetting;

        struct
        {
            char *path = "assets/buttons/change.png";
            SDL_Rect rect{0, 0, 72, 26};
        } change;

        struct
        {
            char *path = "assets/buttons/exit_arrow.png";
            SDL_Rect rect{0, 0, 32, 32};
        } exit;
    } buttons;
};

#endif