#ifndef MOVEOBJECT_H
#define MOVEOBJECT_H

#include "../Object/Cactus.h"
#include "../Object/Ptero.h"
#include "../Object/Dino.h"
#include "../Utils/Texture.h"


class MoveObject
{
private:
    Dino *dino;
    Cactus *cactus;
    Ptero *ptero;

public:
    MoveObject();
    ~MoveObject();

    void update();
    void render(SDL_Renderer *renderer);
    void handleEvent();
    bool isCollide();
    void setDinoDied();
    void reset();
};

#endif