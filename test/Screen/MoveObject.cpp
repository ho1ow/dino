#include "MoveObject.h"

MoveObject::MoveObject()
{
    dino = new Dino(sheet, 1.5);
    cactus = new Cactus(sheet, 1.5);
    ptero = new Ptero(sheet, 1.5);
    if (dino == NULL || cactus == NULL || ptero == NULL)
    {
        std::cerr << "Error: MoveObject::MoveObject() failed to allocate memory for dino, cactus or ptero" << std::endl;
        exit(0);
    }
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
bool MoveObject::isCollide()
{
    if (SDL_HasIntersection(&(cactus->hitBox), &(dino->hitBox)) == SDL_TRUE)
    {
        return true;
    }
    if (SDL_HasIntersection(&(ptero->hitBox), &(dino->hitBox)) == SDL_TRUE)
    {
        return true;
    }
    return false;
}
void MoveObject::setDinoDied()
{
    if (isCollide())
        dino->setDied();
}
void MoveObject::reset()
{

    dino->reset();
    cactus->reset();
    ptero->reset();
}
