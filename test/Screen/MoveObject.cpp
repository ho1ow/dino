#include "MoveObject.h"

MoveObject::MoveObject()
{
    Dino *dino = new Dino(sheet, 1.5);
    Cactus *cactus = new Cactus(sheet, 1.5);
    Ptero *ptero = new Ptero(sheet, 1.5);
}
MoveObject::~MoveObject()
{
    delete dino;
    delete cactus;
    delete ptero;
}

void MoveObject::update()
{
    dino->update();
    cactus->update();
    ptero->update();
}
void MoveObject::render(SDL_Renderer *renderer)
{
    dino->render(renderer, dino->getRect());
    cactus->render(renderer, cactus->getRect());
    ptero->render(renderer, ptero->getRect());
}
void MoveObject::handleEvent()
{
    dino->jump(event);
    dino->duck(event);
}
void MoveObject::handleCollision()
{
    if (SDL_HasIntersection(&(cactus->hitBox), &(dino->hitBox)) == SDL_TRUE)
    {
        SDL_Log("Hit Cactus");
        std::cerr << "died, lose " << std::endl;
    }
    if (SDL_HasIntersection(&(ptero->hitBox), &(dino->hitBox)) == SDL_TRUE)
    {
        SDL_Log("Hit Ptero");
        std::cerr << "died, lose " << std::endl;
    }
}
