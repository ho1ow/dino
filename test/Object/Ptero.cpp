#include "Ptero.h"

Ptero::Ptero(const char *path, const double scale_) : Texture(path, scale_)
{
    crect = &ptero.rect;
    PteroPos = ranPteroPos();
}

void Ptero::getPteroPos()
{
    PteroPos = ranPteroPos();
}

Vector2 Ptero::ranPteroPos()
{
    return {Random::random(SCREEN_WIDTH, Random::random(SCREEN_WIDTH, SCREEN_WIDTH * 3 / 2)), Random::random(SCREEN_HEIGHT / 3, SCREEN_HEIGHT / 2)};
}

void Ptero::getPteroFrame()
{
    static int tmp_fly_w = 0;
    static Uint32 lastFrameTime = 0;
    Uint32 currentTime = SDL_GetTicks();

    tmp_fly_w = tmp_fly_w % 2;
    currentClip.x = ptero.rect.x + ptero.rect.w * tmp_fly_w;
    currentClip.y = ptero.rect.y;
    currentClip.w = ptero.rect.w;
    currentClip.h = ptero.rect.h;
    if (currentTime > lastFrameTime + 200)
    {
        tmp_fly_w++;
        lastFrameTime = currentTime;
    }
    crect = &currentClip;
}

void Ptero::render(SDL_Renderer *renderer, SDL_Rect *rect)
{
    Texture::renderWithPosAndScale(renderer, crect, PteroPos, scale);
}
void Ptero::update()
{
    if (this->offScreen(PteroPos))
    {
        getPteroPos();
    }
    PteroPos.x += PTERO_VEL;
    updateHitBox();
    getPteroFrame();
}
void Ptero::updateHitBox()
{
    hitBox = {PteroPos.x + static_cast<int>(padding * scale), PteroPos.y + static_cast<int>(padding * scale), getRectWidth() - 2 * static_cast<int>(padding * scale), getRectHeight() - 2 * static_cast<int>(padding * scale)};
}
void Ptero::reset()
{
    getPteroPos();
}
