#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

int main(int argc, char *argv[])
{
    // Initialize SDL and SDL_ttf
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    // Create a window and renderer
    SDL_Window *window = SDL_CreateWindow("SDL2_ttf Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Load a font
    TTF_Font *font = TTF_OpenFont("res/fonts/PressStart2P-Regular.ttf", 24);
    if (!font)
    {
        printf("Failed to load font: %s\n", TTF_GetError());
        return 1;
    }

    // Create a surface with some text
    SDL_Color color = {255, 255, 255};
    SDL_Surface *surface = TTF_RenderText_Blended(font, "Hello, SDL2_ttf!", color);

    // Create a texture from the surface
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

    // Render the texture to the screen
    SDL_Rect rect = {0, 0, surface->w, surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &rect);
    SDL_RenderPresent(renderer);

    // Wait for a key press before exiting
    bool quit = false;
    while (!quit)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT || event.type == SDL_KEYDOWN)
            {
                quit = true;
            }
        }
    }

    // Clean up and exit
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
    return 0;
}