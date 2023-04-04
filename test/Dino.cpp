#include "Dino.h"
Dino::Dino() : Object()
{
    width = 0;
    height = 0;
    {

        dinoSpriteClips[0].x = 0;
        dinoSpriteClips[0].y = 0;
        dinoSpriteClips[0].w = 186;
        dinoSpriteClips[0].h = 253;

        dinoSpriteClips[1].x = 0;
        dinoSpriteClips[1].y = 100;
        dinoSpriteClips[1].w = 186;
        dinoSpriteClips[1].h = 253;

        dinoSpriteClips[2].x = 0;
        dinoSpriteClips[2].y = 200;
        dinoSpriteClips[2].w = 186;
        dinoSpriteClips[2].h = 253;

        dinoSpriteClips[3].x = 0;
        dinoSpriteClips[3].y = 300;
        dinoSpriteClips[3].w = 186;
        dinoSpriteClips[3].h = 253;
    }
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
            playerVelY = JUMP_VELOCITY;
            jumping = true;
            jumpDelay = JUMP_DELAY_TIME;
        }
    }
}
void Dino::handleInput()
{
    // Update player position with fixed time step
    crect.y += playerVelY * 10 * FRAME_TIME / 200;

    if (jumping && jumpDelay > 0)
    {
        // Apply delay animation
        jumpDelay--;
        crect.y -= jumpDelay;
    }
    else
    {
        // Apply gravity
        playerVelY += GRAVITY;

        // Check if player hits the bottom of the screen
        if (crect.y + 700 > SCREEN_HEIGHT)
        {
            crect.y = SCREEN_HEIGHT - 700;
            playerVelY = 0;
            jumping = false;
        }
    }
}

void Dino::render(int x, int y, SDL_Rect *clip)
{
    // Set rendering space and render to screen
    SDL_Rect renderQuad = {x, y, width, height};

    // Set clip rendering dimensions
    if (clip != NULL)
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }

    // Render to screen
    SDL_RenderCopy(renderer, ctexture, clip, &renderQuad);
}