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
        switch (event.type)
        {
        case SDL_QUIT:
            isRunning = false;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                isRunning = false;
                break;
            case SDLK_SPACE:
                if (isGameOver)
                {
                    isReset = true;
                }
                if(isPause)
                {
                    isPause=false;
                }
                break;
            case SDLK_p:
                if(!isGameOver)
                {
                    isPause=!isPause;
                }
                break;
            case SDLK_1:
                background->setIsDay();
                break;
            case SDLK_2:
                background->setIsNight();
                break;
            default:
                break;
            }
            break;
        
        default:
            break;
        }
        if(!isGameOver && !isPause)
        {
            moveObject->handleEvent();
        }
    }
    handleCollision();
}
void Game::render()
{

    background->renderCloudAndRoad(renderer);
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
    background->renderGameOver(renderer);
    if (isReset)
    {
        reset();
        isReset = false;
    }
}
void Game::reset()
{
    background->reset();
    moveObject->reset();
    isCollide = false;
    isGameOver = false;
}

void Game::run()
{
    while (isRunning)
    {
        background->renderBg(renderer);

        render();
        update();
        handleEvents();

        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);
    }
}
