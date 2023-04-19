#include "Game.h"
#include "../Utils/Timer.h"

bool Game::isGameOver = false;
bool Game::isPause = false;
bool Game::isReset = false;

Game::Game()
{
    isRunning = true;
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
    if (isGameOver || isPause)
    {
        return;
    }
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
            else if (event.key.keysym.sym == SDLK_SPACE)
            {
                if (isGameOver)
                {
                    isReset = true;
                }
            }
            else if (event.key.keysym.sym == SDLK_p)
            {
                
                paused();
            }
            else if (event.key.keysym.sym == SDLK_r)
            {
                resume();
            }
        }
        // std::cerr << "Reset :" << isGameOver << std::endl;

        moveObject->handleEvent();
    }
    handleCollision();
}
void Game::render()
{
    background->renderBg(renderer);
    moveObject->render(renderer);
}

void Game::handleCollision()
{
    isCollide = moveObject->isCollide();
    if (isCollide)
    {
        moveObject->setDinoDied();
        gameOver();
    }
}
void Game::gameOver()
{
    isGameOver = true;
    if (isReset)
    {
        reset();
        isReset = false;
    }
}
void Game::reset()
{
    moveObject->reset();
    isCollide = false;
    isGameOver = false;
}

void Game::paused()
{
    isPause = true;
}
void Game::resume()
{
    isPause = false;
}
void Game::run()
{
    int x = 0;
    while (isRunning)
    {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        update();
        render();
        handleEvents();

        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);
    }
}
