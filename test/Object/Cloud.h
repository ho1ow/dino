#ifndef DINO_CLOUD_H
#define DINO_CLOUD_H

#include "../Texture.h"

class Cloud : public Texture
{
protected:
    static const int MAX_CLOUDS = 5;
    static const int CLOUD_VEL = -5;
    const int MIN_CLOUD_DIST = 150;

    Vector clouds[MAX_CLOUDS];

    SDL_Rect cloud{166, 2, 92, 27};

public:
    Cloud(const char *path);

    ~Cloud(){};

    Vector ranCloudPos();

    void render(SDL_Renderer *renderer, SDL_Rect *rect);
    void update();

    void reset();
};

#endif