#include "Dino.h"

Dino::Dino(const char *path, const double scale_) : Texture(path, scale_)
{
    crect = &dino.move;
    dinoPos = {0, SCREEN_HEIGHT - crect->h};
}
int tmp_w = 0;
Dino::~Dino()
{
}

void Dino::jump(SDL_Event &event)
{

    if (event.type == SDL_KEYDOWN)
    {
        if (event.key.keysym.sym == SDLK_SPACE && !isJumping)
        {
            // Start jump
            velY = JUMP_VELOCITY;
            isJumping = true;
            jumpDelay = JUMP_DELAY_TIME;
        }
    }
}
void Dino::duck(SDL_Event &event)
{
    if (event.type == SDL_KEYDOWN)
    {
        if (event.key.keysym.sym == SDLK_DOWN && !isDucking)
        {
            isDucking = true;
        }
    }
    else if (event.type == SDL_KEYUP)
    {
        if (event.key.keysym.sym == SDLK_DOWN && isDucking)
        {
            isDucking = false;
        }
    }
}
void Dino::updatePos()
{
    dinoPos.y += velY;

    if (isJumping && jumpDelay > 0)
    {
        jumpDelay--;
        dinoPos.y -= jumpDelay;
    }
    else
    {
        velY += GRAVITY;

        if (dinoPos.y + getRectHeight() + 20 > SCREEN_HEIGHT)
        {
            dinoPos.y = SCREEN_HEIGHT - getRectHeight() - 20;
            velY = 0;
            isJumping = false;
        }
    }
}

void Dino::getDinoFrame()
{
    static int tmp_move_w = 0;
    static int tmp_duck_w = 0;
    static Uint32 lastFrameTime = 0;
    Uint32 currentTime = SDL_GetTicks();

    if (isJumping)
    {
        // jump frame
        currentClip = dino.move;
    }
    else if (isDucking)
    {
        // duck frame
        tmp_duck_w = tmp_duck_w % 2;
        currentClip.x = dino.duck.x + dino.duck.w * tmp_duck_w;
        currentClip.y = dino.duck.y;
        currentClip.w = dino.duck.w;
        currentClip.h = dino.duck.h;
        if (currentTime - lastFrameTime > 200)
        {
            tmp_duck_w++;
            lastFrameTime = currentTime;
        }
    }
    else
    {
        // move frame
        tmp_move_w = tmp_move_w % 4;
        currentClip.x = dino.move.x + dino.move.w * tmp_move_w;
        currentClip.y = dino.move.y;
        currentClip.w = dino.move.w;
        currentClip.h = dino.move.h;

        if (currentTime - lastFrameTime > 100)
        {
            tmp_move_w++;
            lastFrameTime = currentTime;
        }
    }

    crect = &currentClip;
}
void Dino::updateHitBox()
{
    hitBox = {dinoPos.x + static_cast<int>(padding * 1.5 * scale), dinoPos.y + static_cast<int>(padding * scale), getRectWidth() - static_cast<int>(padding * 2 * scale), getRectHeight() - static_cast<int>(padding * 2 * scale)};
}
void Dino::update()
{
    updatePos();
    getDinoFrame();
    updateHitBox();
}

void Dino::render(SDL_Renderer *renderer_, SDL_Rect *rect)
{

    if (!died)
    {
        Texture::renderWithPosAndScale(renderer_, crect, dinoPos, scale);
    }
    else
    {

        if (dinoPos.y >= 569)
        {
            dinoPos.y = 539;
        }
        Texture::renderWithPosAndScale(renderer_, &dino.died, dinoPos, scale);
    }
}

Vector Dino::getPos()
{
    return dinoPos;
}

void Dino::setDied()
{
    died = true;
}
void Dino::setLive()
{
    died = false;
}
void Dino::reset()
{
    died = false;
    dinoPos = {0, SCREEN_HEIGHT - crect->h};
    velY = 0;
    isJumping = false;
    isDucking = false;
}