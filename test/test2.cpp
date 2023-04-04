#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

const int FPS = 60;
const int FRAME_TIME = 1000 / FPS;

int main(int argc, char *args[])
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow("Jumping with Gravity",
                                          SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                          SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Load player texture
    SDL_Texture *playerTexture = IMG_LoadTexture(renderer, "res/img/dino.png");

    // Player position and velocity
    int playerX = SCREEN_WIDTH / 2;
    int playerY = SCREEN_HEIGHT / 2;
    int playerVelY = 0;

    // Gravity
    const int GRAVITY = 1;

    // Jump velocity
    const int JUMP_VELOCITY = -10;

    // Delay animation
    bool jumping = false;
    int jumpDelay = 0;
    const int JUMP_DELAY_TIME = 20;

    // Frame timing variables
    Uint32 frameStart;
    int frameTime;

    // Destination rectangle for player texture
    SDL_Rect playerRect = {playerX, playerY, 50, 50};

    bool quit = false;
    SDL_Event e;

    while (!quit)
    {
        // Get frame start time
        frameStart = SDL_GetTicks();

        // Handle keyboard input
        const Uint8 *keyboardState = SDL_GetKeyboardState(NULL);
        if (keyboardState[SDL_SCANCODE_SPACE] && !jumping)
        {
            // Start jump
            playerVelY = JUMP_VELOCITY;
            jumping = true;
            jumpDelay = JUMP_DELAY_TIME;
        }

        // Update player position with fixed time step
        playerY += playerVelY * 50 * FRAME_TIME / 1000;

        if (jumping && jumpDelay > 0)
        {
            // Apply delay animation
            jumpDelay--;
            playerY -= jumpDelay;
        }
        else
        {
            // Apply gravity
            playerVelY += GRAVITY;

            // Check if player hits the bottom of the screen
            if (playerY + 50 >= SCREEN_HEIGHT)
            {
                // Player is on the ground
                playerY = SCREEN_HEIGHT - 50;
                playerVelY = 0;
                jumping = false;
            }
        }

        // Clear screen
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Set player texture destination
        playerRect.y = playerY;

        // Draw player texture
        SDL_RenderCopy(renderer, playerTexture, NULL, &playerRect);

        // Update screen
        SDL_RenderPresent(renderer);

        // Limit frame rate
        frameTime = SDL_GetTicks() - frameStart;
        if (frameTime < FRAME_TIME)
        {
            SDL_Delay(FRAME_TIME - frameTime);
        }
    }

    SDL_DestroyTexture(playerTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}