#include "Dino.h"

Uint32 DINO_startTicks = 0;
Uint32 DINO_startTicks2 = 0;
const Uint32 DINO_spritetime = 100;

int tmp_w = 0;

SDL_Rect currentClip;
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
void Dino::duck(SDL_Event &event)
{
    if (event.type == SDL_KEYDOWN)
    {
        if (event.key.keysym.sym == SDLK_DOWN && !ducking)
        {
            // Start duck with delay
            ducking = true;
        }
    }
    else if (event.type == SDL_KEYUP)
    {
        if (event.key.keysym.sym == SDLK_DOWN && ducking)
        {
            // End duck
            ducking = false;
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
        if (crect.y + crect.h + 540 > SCREEN_HEIGHT)
        {
            crect.y = SCREEN_HEIGHT - crect.h - 540;
            velY = 0;
            jumping = false;
        }
    }
}

SDL_Rect *Dino::setFrameMove()
{

    Uint32 currentTicks = SDL_GetTicks();
    currentClip = dino.move.rect;
    if (currentTicks - DINO_startTicks > DINO_spritetime)
    {
        if (jumping)
        {
            currentClip = dino.move.rect;
        }
        else
        {
            tmp_w = (tmp_w % 2 == 0) ? 3 : 2;
            currentClip.x = dino.move.rect.x + dino.move.rect.w * tmp_w;
        }
        DINO_startTicks = currentTicks;
    }
    return &currentClip;
}

SDL_Rect *Dino::setFrameDuck()
{
    Uint32 currentTicks = SDL_GetTicks();
    currentClip = dino.duck.rect;
    tmp_w=1;
    if (currentTicks - DINO_startTicks2 > DINO_spritetime)
    {
        if (ducking)
        {
            tmp_w = (tmp_w % 2 == 0) ? 0 : 1;
            currentClip.x = dino.duck.rect.x + dino.duck.rect.w * tmp_w;
        }
        DINO_startTicks2 = currentTicks;
    }
    return &currentClip;
}
void Dino::render()
{
    if (ducking)
    {
        crect.w = 118;
        crect.h = 62;
        SDL_Rect destRect = {crect.x, crect.y, crect.w, crect.h};
        SDL_RenderCopy(renderer, ctexture, setFrameDuck(), &destRect);
    }
    else
    {
        crect.w = 88;
        crect.h = 94;
        SDL_Rect destRect = {crect.x, crect.y, crect.w, crect.h};

        SDL_RenderCopy(renderer, ctexture, setFrameMove(), &destRect);
    }
    std::cerr << tmp_w << " " << currentClip.x << "\n";
}
