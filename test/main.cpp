#include "commonVar.h"
#include "backGround.h"
#include "ObjectManager.h"
#include "Dino.h"

Uint32 frameStart;
int frameTime;

BackGround *backGround = new BackGround();

Dino *newDino = new Dino(64, 63, dino);
Dino *dinoSheet = new Dino(744, 253, dinoSprite);

int main(int argc, char *argv[])
{
    backGround->loading_background(renderer, "res/img/bg.png");

    if (newDino->get_text() == NULL)
    {
        std::cerr << "error";
        exit(EXIT_FAILURE);
    }
    bool isRunning = true;
    while (isRunning)
    {

        backGround->render_background_scroll(renderer);
        backGround->update_background_scroll();
        backGround->set_speed(7);

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
            // newDino->jump(event);
            dinoSheet->jump(event);
        }

        // newDino->handleInput();
        // newDino->renderWithScale(renderer, 1);
        dinoSheet->handleInput();
        dinoSheet->move();
        dinoSheet->render(dinoSheet->currentClip);

        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);
        

        frameTime = SDL_GetTicks() - frameStart;
        if (frameTime < FRAME_TIME)
        {
            SDL_Delay(FRAME_TIME - frameTime);
        }
    }
}