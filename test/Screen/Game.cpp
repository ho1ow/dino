#include "Game.h"

Game::Game()
{
    isRunning = true;
    isGameOver = false;
    isPause = false;
    isReset = false;
    isPlay = false;
    isMute = false;

    background = new Background();
    moveObject = new MoveObject();
    menu = new Menu();
    score = new Score();

}
Game::~Game()
{
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
            case SDLK_p:
                if (!isGameOver)
                {
                    if (!isPause)
                    {
                        paused();
                    }
                    else
                    {
                        resume();
                    }
                }
                break;
            case SDLK_m:
                if (isMute)
                {
                    unmute();
                }
                else
                {
                    mute();
                }
                break;
            case SDLK_SPACE:
                if (isGameOver)
                {
                    isReset = true;
                }
                if (isPause)
                {
                    resume();
                }
                if (!isPlay)
                {
                    isPlay = true;
                }
                break;
            case SDLK_1:
                background->setIsDay();
                break;
            case SDLK_2:
                background->setIsNight();
                break;
            case SDLK_b:
                if (isGameOver)
                {
                    returnMenu();
                }
                break;
            default:
                break;
            }

        case SDL_MOUSEBUTTONDOWN:
            handleMouseClick();
            break;
        default:
            break;
        }
        if (!isGameOver && !isPause)
        {
            moveObject->handleEvent();
        }
    }
    if (isPlay)
    {
        handleCollision();
    }
}
void Game::update()
{
    if (isGameOver || isPause || !isPlay)
    {
        return;
    }
    background->update();
    moveObject->update();
    score->update(100);
}
void Game::render()
{
    background->renderCloudAndRoad(renderer);
    moveObject->render(renderer);
    score->render();
}
void Game::gameOver()
{
    background->renderGameOver(renderer);
    isGameOver = true;

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
    score->reset();
    isGameOver = false;
}
void Game::returnMenu()
{
    reset();
    background->update();
    moveObject->update();
    score->update(0);
    isPlay = false;
}
void Game::paused()
{
    isPause = true;
    background->pauseBg();
}
void Game::resume()
{
    isPause = false;
    background->resumeBg();
}
void Game::mute()
{
    isMute = true;
}
void Game::unmute()
{
    isMute = false;
}
void Game::handleCollision()
{
    if (moveObject->isCollide())
    {
        moveObject->setDinoDied();
        gameOver();
    }
}
void Game::handleMouseClick()
{
    if (event.button.button == SDL_BUTTON_LEFT)
    {
        if (menu->play->isInside())
        {
            isPlay = true;
        }
        if (menu->exit->isInside())
        {
            isRunning = false;
        }
        if (background->pause->isInside())
        {
            if (!isGameOver)
            {
                if (!isPause)
                {
                    paused();
                }
                else
                {
                    resume();
                }
            }
        }
    }
}

void Game::run()
{
    while (isRunning)
    {
        std::cerr << isPlay << " " << moveObject->isCollide() << std::endl;
        if (!isPlay)
        {
            menu->render(renderer);
            menu->update();
        }
        else
        {
            background->renderBg(renderer);
            render();
            update();
        }

        handleEvents();

        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);
    }
}
