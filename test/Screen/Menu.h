#ifndef MENU_H
#define MENU_H

#include "../Button/Button.h"

class Menu
{
private:
    Texture *bg;

public:
    Menu();
    ~Menu();

    Button *play;
    Button *exit;
    
    void render(SDL_Renderer *renderer);
    void update();
    void reset();
};

#endif