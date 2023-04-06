#include "commonVar.h"

class Dino
{
protected:
    const int WALKING_ANIMATION_FRAMES = 2;
    SDL_Texture *ctexture;
    SDL_Rect crect;

    const int GRAVITY = 1;
    // Jump velocity
    const int JUMP_VELOCITY = -10;

    // Delay animation
    bool jumping = false;
    int jumpDelay = 0;
    const int JUMP_DELAY_TIME = 20;

    bool ducking = false;
    int duckDelay = 0;
    int duckingEnd = 0;
    const int DUCK_DELAY_TIME = 1000;
    static const int DUCK_FRAME_DELAY = 8;

    int velY = 0;

public:
    Dino(int w, int h, const char *path);
    ~Dino();

    struct
    {
        struct
        {
            SDL_Rect rect{1678, 2, 88, 94};
            int frameCount = 4;
        } move;
        struct
        {
            SDL_Rect rect{2205, 35, 118, 62};
            int frameCount = 2;
        } duck;

        SDL_Rect died = {2030, 2, 88, 94};

    } dino;

    void handleInput();
    void jump(SDL_Event &event);
    void duck(SDL_Event &event);
    SDL_Rect *setFrameMove();
    SDL_Rect *setFrameDuck();
    void render();
};