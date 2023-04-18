#include "commonVar.h"
#include "ObjectManager.h"
#include "Screen/Game.h"

Dino *dino = new Dino(sheet, 1.5);
Road *road = new Road(sheet);
Cloud *cloud = new Cloud(sheet);
Cactus *cactus = new Cactus(sheet, 1.5);
Ptero *ptero = new Ptero(sheet, 1.5);


int oldmain()
{
    bool isRunning = true;
    while (isRunning)
    {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        cloud->render(renderer, cloud->getRect());
        road->renderScroll(renderer, road->getRect());
        cactus->render(renderer, cactus->getRect());
        ptero->render(renderer, ptero->getRect());
        dino->render(renderer, dino->getRect());

        cloud->update();
        road->update(road->getRect());
        road->set_speed(4);
        cactus->update();
        ptero->update();
        dino->update();
        
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                isRunning = false;
            }
            if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                    isRunning = false;
                }
            }
            dino->jump(event);
            dino->duck(event);
        }

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

        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);
    }
}