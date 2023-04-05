#include "commonVar.h"

class Dino
{
protected:
    const int WALKING_ANIMATION_FRAMES = 2;
    SDL_Texture *ctexture;
    SDL_Rect crect;

    const int GRAVITY = 2;
    // Jump velocity
    const int JUMP_VELOCITY = -10;

    // Delay animation
    bool jumping = false;
    int jumpDelay = 0;
    const int JUMP_DELAY_TIME = 20;
    int velY = 0;

public:
    Dino(int w, int h, const char *path);
    ~Dino();
    SDL_Rect dinoSpriteClips[4] = {

        {0, 0, FRAME_WIDTH, FRAME_HEIGHT},
        {FRAME_WIDTH, 0, FRAME_WIDTH, FRAME_HEIGHT},
        {FRAME_WIDTH * 2, 0, FRAME_WIDTH, FRAME_HEIGHT},
        {FRAME_WIDTH * 3, 0, FRAME_WIDTH, FRAME_HEIGHT},
    };

    void handleInput();
    void jump(SDL_Event &event);
    SDL_Rect *setFrameMove();
    void render();
};