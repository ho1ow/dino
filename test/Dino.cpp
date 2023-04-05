#include "Dino.h"

Uint32 DINO_startTicks = 0;
Uint32 DINO_spriteIndex = 0;
const Uint32 DINO_spritetime = 50;

Dino::Dino(int w, int h, const char *path)
{
    ctexture = IMG_LoadTexture(renderer, path);
    crect.w = w;
    crect.h = h;
    crect.x = 0;
    crect.y = 0;
}
Dino::~Dino()
{
}

void Dino::jump(SDL_Event &event)
{

    if (event.type == SDL_KEYDOWN)
    {
        if (event.key.keysym.sym == SDLK_SPACE && !jumping)
        {
            // Start jump
            velY = JUMP_VELOCITY;
            jumping = true;
            jumpDelay = JUMP_DELAY_TIME;
        }
    }
}
void Dino::handleInput()
{
    // Update player position with fixed time step
    crect.y += velY;

    if (jumping && jumpDelay > 0)
    {
        // Apply delay animation
        jumpDelay--;
        crect.y -= jumpDelay;
    }
    else
    {
        // Apply gravity
        velY += GRAVITY;

        // Check if player hits the bottom of the screen
        if (crect.y + crect.h +520> SCREEN_HEIGHT)
        {
            crect.y = SCREEN_HEIGHT - crect.h-520;
            velY = 0;
            jumping = false;
        }
    }
}

SDL_Rect *Dino::setFrameMove()
{

    Uint32 currentTicks = SDL_GetTicks();
    if (currentTicks - DINO_startTicks > DINO_spritetime)
    {
        DINO_spriteIndex = (DINO_spriteIndex % 2 == 0) ? 1 : 2;
        DINO_startTicks = currentTicks;
    }
    return &dinoSpriteClips[DINO_spriteIndex];
}
void Dino::render()
{

    SDL_Rect destRect = {crect.x, crect.y, FRAME_WIDTH, FRAME_HEIGHT};

    // Render to screen
    SDL_RenderCopy(renderer, ctexture, setFrameMove(), &destRect);
}
