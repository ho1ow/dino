#ifndef DINO_H
#define DINO_H
#include "../Utils/Texture.h"

class Dino : public Texture
{
private:
    const int padding = 20;

    const int GRAVITY = 1;
    const int JUMP_VELOCITY = -5;

    bool isJumping = false;
    int jumpDelay = 0;
    const int JUMP_DELAY_TIME = 20;

    bool isDucking = false;
    int duckDelay = 0;

    int velY = 0;

    bool died = false;
    int soundDeath;

    Vector dinoPos = {};
    SDL_Rect currentClip = dino.move;

    struct
    {

        SDL_Rect move{1678, 2, 88, 94};
        SDL_Rect duck{2205, 35, 118, 62};
        SDL_Rect died = {2030, 2, 88, 94};

    } dino;

public:
    Dino(const char *path, const double scale);
    ~Dino();

    SDL_Rect hitBox;

    void updatePos();
    void jump(SDL_Event &event);
    void duck(SDL_Event &event);

    Vector getPos();
    void getDinoFrame();
    void render(SDL_Renderer *renderer, SDL_Rect *rect);
    void update();
    void updateHitBox();

    void setDied();
    void setLive();
    void reset();


};
#endif