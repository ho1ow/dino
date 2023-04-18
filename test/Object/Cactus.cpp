#include "Cactus.h"

Cactus::Cactus(const char *path, const double scale_) : Texture(path, scale_)
{
    crect = &cactus[ranCactusType()];
    getCactusPos();
    hitBox = {cactusPos.x + padding, cactusPos.y + padding, getRectWidth() - padding * 2, getRectHeight() - padding * 2};
}

int Cactus::ranCactusType()
{
    return Random::random(0, 5);
}

void Cactus::getCactusType()
{
    crect = &cactus[ranCactusType()];
}

Vector2 Cactus::ranCactusPos()
{

    return {Random::random(SCREEN_WIDTH, Random::random(SCREEN_WIDTH, SCREEN_WIDTH * 2)), SCREEN_HEIGHT - getRectHeight() - 5};
}

void Cactus::getCactusPos()
{
    cactusPos = ranCactusPos();
}

void Cactus::render(SDL_Renderer *renderer_, SDL_Rect *rect)
{
    Texture::renderWithPosAndScale(renderer_, crect, cactusPos, scale);
}

void Cactus::update()
{
    if (this->offScreen(cactusPos))
    {
        getCactusType();
        getCactusPos();
    }
    cactusPos.x += CACTUS_VEL;
    hitBox = {cactusPos.x + padding, cactusPos.y + padding, getRectWidth() - padding * 2, getRectHeight() - padding * 2};
    std::cerr << "cactus" << hitBox.x << " " << hitBox.y << " " << hitBox.h << " " << hitBox.w << "\n";
}
