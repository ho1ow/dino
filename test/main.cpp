#include "commonVar.h"
#include "backGround.h"
#include "ObjectManager.h"
#include "Dino.h"

BackGround *backGround = new BackGround();
Dino *dinoSheet = new Dino(FRAME_SHEET_WIDTH, FRAME_SHEET_HEIGHT, dinoSprite);

int main(int argc, char *argv[])
{
    backGround->loading_background(renderer, "res/img/bg.png");

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
            dinoSheet->jump(event);
        }

        dinoSheet->handleInput();
        dinoSheet->render();

        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);
    }
}