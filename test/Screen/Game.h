#ifndef GAME_H
#define GAME_H

#include "Background.h"
#include "MoveObject.h"

class Game
{
private:
    Background *background;
    MoveObject *moveObject;
    
    static bool isGameOver;
    static bool isPause;
    static bool isReset;

public:
    Game();
    ~Game();
    bool isRunning;

    void handleEvents();
    void update();
    void render();

    bool isCollide;
    void handleCollision();

    void gameOver();
    void reset();
    
    static void paused();
    static void resume();

    void run();
};

#endif
