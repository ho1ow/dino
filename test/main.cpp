#include "commonVar.h"
#include "ObjectManager.h"
#include "Screen/Game.h"

Game *game = new Game();

int main(int argc, char *argv[])
{
    bool isRunning = true;
    while (isRunning)
    {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        game->render();
        game->update();
        game->handleEvents();

        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);
    }
}