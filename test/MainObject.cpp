#include "MainObject.h"

player::player()
{
    ctexture = IMG_LoadTexture(renderer, "res/img/icon.png");

    crect.x = 100;
    crect.y = 100;
    crect.w = 64;
    crect.h = 63;
}

player::~player()
{
}
void player::load_sprite(SDL_Renderer *renderer, const char *file)
{
}

void player::render_sprite(SDL_Renderer *renderer, const double &scale)
{
    crect.w = static_cast<int>(64 * scale);
    crect.h = static_cast<int>(63 * scale);
    SDL_Rect destRect = {crect.x, crect.y, crect.w, crect.h};

    // Render the current sprite

    // This sets the texture in blendmode.
    SDL_SetTextureBlendMode(ctexture, SDL_BLENDMODE_BLEND);

    SDL_RenderCopy(renderer, ctexture, nullptr, &destRect);
}

void player::set_rect_cordinate(const int &x, const int &y)
{
    crect.x = x;
    crect.y = y;
}
void player::set_rect_cordinate_width_and_height(const int &x, const int &y, const int &width, const int &height)
{
    crect.x = x;
    crect.y = y;
    crect.w = width;
    crect.h = height;
}
void player::set_rect_width_and_height(const int &width, const int &height)
{
    crect.w = width;
    crect.h = height;
}

// void player::handlingMovement(SDL_Event &event)
// {
//     if (event.type == SDL_KEYDOWN)
//     {
//         // Set texture based on current keystate
//         const Uint8 *currentKeyStates = SDL_GetKeyboardState(NULL);

//         if (currentKeyStates[SDL_SCANCODE_W])
//         {
//             crect.y -= 100;
//         }
//         else if (currentKeyStates[SDL_SCANCODE_S])
//         {
//             crect.y += 100;
//         }
//         else if (currentKeyStates[SDL_SCANCODE_A])
//         {
//             crect.x -= 100;
//         }
//         else if (currentKeyStates[SDL_SCANCODE_D])
//         {
//             crect.x += 100;
//             std::cerr << crect.x << "\n";
//         }
//     }
//     else if (event.type == SDL_KEYUP)
//     {
//         const Uint8 *currentKeyStates = SDL_GetKeyboardState(NULL);

//         if (currentKeyStates[SDL_SCANCODE_W])
//         {
//             crect.y += 100;
//         }
//         else if (currentKeyStates[SDL_SCANCODE_S])
//         {
//             crect.y -= 100;
//         }
//         else if (currentKeyStates[SDL_SCANCODE_A])
//         {
//             crect.x += 100;
//         }
//         else if (currentKeyStates[SDL_SCANCODE_D])
//         {
//             crect.x -= 100;
//         }
//     }

//     else
//     {
//         return;
//     }
// }
void player::handlingMovement(SDL_Event &event)
{
    int yMovement = 0;
    int xMovement = 0;

    if (currentKeyStates[SDL_SCANCODE_W])
    {
        yMovement -= 10;
    }
    else if (currentKeyStates[SDL_SCANCODE_S])
    {
        yMovement += 10;
    }
    else if (currentKeyStates[SDL_SCANCODE_A])
    {
        xMovement -= 10;
    }
    else if (currentKeyStates[SDL_SCANCODE_D])
    {
        xMovement += 10;
        std::cerr << crect.x << "\n";
    }

    crect.x += xMovement;
    crect.y += yMovement;
    return;
}
SDL_Rect player::get_rect() const
{
    return crect;
}
SDL_Rect player::get_rect_width_height_with_scale(const double &scale) const
{
    SDL_Rect rect = {crect.x, crect.y, static_cast<int>(crect.w * scale), static_cast<int>(crect.h * scale)};
    return rect;
}