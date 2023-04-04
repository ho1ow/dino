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
    SDL_Rect dinoSpriteClips[4];

public:
    Dino();
    ~Dino();

    void handleInput();
    void jump(SDL_Event &event);
    void render(int x, int y, SDL_Rect *clip);
};