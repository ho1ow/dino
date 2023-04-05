#include "Dino.h"
Dino::Dino(int w, int h, const char *path) : Object()
{
    ctexture = IMG_LoadTexture(renderer, path);
    crect.w = w;
    crect.h = h;
    width = 0;
    height = 0;
    currentClip = new SDL_Rect;
    currentClip->x = crect.x;
    currentClip->w = crect.w;
    currentClip->h = crect.h;
    currentClip->y = SCREEN_HEIGHT - currentClip->h;
}
Dino::~Dino()
{
    delete currentClip;
}

void Dino::jump(SDL_Event &event)
{

    if (event.type == SDL_KEYDOWN)
    {
        if (event.key.keysym.sym == SDLK_SPACE && !jumping)
        {
            // Start jump
            playerVelY = JUMP_VELOCITY;
            jumping = true;
            jumpDelay = JUMP_DELAY_TIME;
        }
    }
}
void Dino::handleInput()
{
    // Update player position with fixed time step
    currentClip->y += playerVelY * 10 * FRAME_TIME / 200;

    if (jumping && jumpDelay > 0)
    {
        // Apply delay animation
        jumpDelay--;
        // currentClip->y -= jumpDelay;
        currentClip->y += playerVelY;
    }
    else
    {
        // Apply gravity
        playerVelY += GRAVITY;

        // Check if player hits the bottom of the screen
        if (currentClip->y + currentClip->h > SCREEN_HEIGHT)
        {
            currentClip->y = SCREEN_HEIGHT - currentClip->h;
            playerVelY = 0;
            jumping = false;
        }
    }
}

void Dino::move()
{
    // Cycle to next frame
    ++frameCount;
    if (frameCount / 2 >= WALKING_ANIMATION_FRAMES)
    {
        frameCount = 0;
    }

    // Update currentClip pointer to point to the correct sprite clip
    currentClip = &(dinoSpriteClips[frameCount / 2]);

    // Render sprite with currentClip
    render(currentClip);
}
void Dino::render(SDL_Rect *clip)
{

    SDL_Rect destRect = {0, currentClip->y, currentClip->w, currentClip->h};

    // Render to screen
    SDL_RenderCopy(renderer, ctexture, clip, &destRect);
}
