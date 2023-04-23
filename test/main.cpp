#include "Screen/Game.h"

Game *game = new Game();

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    game->run();
}