#include "Cloud.h"
Cloud::Cloud(const char *path) : Texture(path)
{
    crect = &cloud;
    for (auto &pos : clouds)
    {
        pos = ranCloudPos();
    }
}

// Vector Cloud::ranCloudPos()
// {
//     return {Random::random(SCREEN_WIDTH, Random::random(SCREEN_WIDTH, SCREEN_WIDTH * 4)), Random::random(150, SCREEN_HEIGHT / 3)};
// }
Vector Cloud::ranCloudPos()
{
    Vector newPos;
    bool validPos = false;
    while (!validPos)
    {
        newPos = {Random::random(SCREEN_WIDTH, Random::random(SCREEN_WIDTH, SCREEN_WIDTH * 4)), Random::random(150, SCREEN_HEIGHT / 3)};
        validPos = true;
        for (auto &pos : clouds)
        {
            if (Vector::distance(newPos, pos) < MIN_CLOUD_DIST)
            {
                validPos = false;
                break;
            }
        }
    }
    return newPos;
}

void Cloud::render(SDL_Renderer *renderer_, SDL_Rect *rect)
{

    for (auto &pos : clouds)
    {
        Texture::renderWithPos(renderer_, crect, pos);
    }
}

void Cloud::update()
{
    for (auto &pos : clouds)
    {
        if (this->offScreen(pos))
        {
            pos = ranCloudPos();
        }
        pos.x += CLOUD_VEL;
    }
}
void Cloud::reset()
{
    for (auto &pos : clouds)
    {
        pos = ranCloudPos();
    }
}