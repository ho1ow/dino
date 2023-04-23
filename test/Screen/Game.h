#ifndef GAME_H
#define GAME_H

#include "Background.h"
#include "MoveObject.h"
#include "Menu.h"
#include "../Object/Score.h"

class Game
{
private:
    Background *background;
    MoveObject *moveObject;
    Menu *menu;
    Score *score;

    bool isRunning;
    bool isPlay;
    bool isGameOver;
    bool isPause;
    bool isReset;
    bool isMute;
    bool isCollide;
    bool isReturnMenu;

public:
    Game();
    ~Game();

    void handleEvents();
    void update();
    void render();

    void handleCollision();
    void handleMouseClick();

    void gameOver();
    void reset();

    void paused();
    void resume();

    void mute();
    void unmute();

    void returnMenu();

    void run();


};


#endif
