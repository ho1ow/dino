#include "commonVar.h"
#include "backGround.h"
#include "MainObject.h"
BackGround *backGround = new BackGround();
player *newPlayer = new player();
int main(int argc, char *argv[])
{
    backGround->loading_background(renderer, "res/img/bg.png");
    newPlayer->set_rect_cordinate(0, 0);
    if (newPlayer->get_text() == NULL)
    {
        std::cout << "error";
        exit(EXIT_FAILURE);
    }
    bool isRunning = true;
    while (isRunning)
    {

        backGround->render_background_scroll(renderer);
        backGround->update_background_scroll();
        backGround->set_speed(2);

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
            newPlayer->handlingMovement(event);
        }
        // newPlayer->set_rect_cordinate();
        newPlayer->render_sprite(renderer, 3);
        SDL_RenderPresent(renderer);

        SDL_RenderClear(renderer);
    }
}