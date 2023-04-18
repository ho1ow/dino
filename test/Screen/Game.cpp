#include "Game.h"

Game::Game()
{
    background = new Background();
    moveObject = new MoveObject();
}
Game::~Game()
{
    delete background;
    delete moveObject;
}
void Game::update()
{
    background->update();
    moveObject->update();
}
void Game::handleEvents()
{
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
        moveObject->handleEvent();
    }
}
void Game::render()
{
    background->renderBg(renderer);
    moveObject->render(renderer);
}