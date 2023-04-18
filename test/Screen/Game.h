#ifndef GAME_H
#define GAME_H

#include "Background.h"
#include "MoveObject.h"

class Game
{
private:
    Background *background;
    MoveObject *moveObject;

    bool isRunning = true;

public:
    Game();
    ~Game();

    void handleEvents();
    void update();
    void render();
    void clean();

};

#endif
