#include "commonVar.h"
#include "ObjectManager.h"

class Dino : public Object
{
protected:
    // Gravity
    const int GRAVITY = 2;

    // Jump velocity
    const int JUMP_VELOCITY = -12;

    // Delay animation
    bool jumping = false;
    int jumpDelay = 0;
    const int JUMP_DELAY_TIME = 20;
    int playerVelY = 0;

    int width, height;
    const int WALKING_ANIMATION_FRAMES = 2;

public:
    Dino(int w, int h, const char *path);
    ~Dino();
    SDL_Rect dinoSpriteClips[4] = {

        {0, 0, 186, 253},
        {186, 0, 186, 253},
        {186 * 2, 0, 186, 253},
        {186 * 3, 0, 186, 253},
    };
    SDL_Rect *currentClip;

    int frameCount = 2;

    void handleInput();
    void jump(SDL_Event &event);
    void move();
    void render(SDL_Rect *clip);
};