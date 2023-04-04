#include "commonVar.h"
class input
{
private:
    input();

    Uint8 *lastKeyState;
    const Uint8 *currentKeyState;
    int keyStateLength{};

public:
    bool keyDown(SDL_Scancode keycode);
    bool keyPressed(SDL_Scancode keycode);
    bool keyUp(SDL_Scancode keycode);
    /**
     * Update key state ( should be call before render )
     */
    void updateKeyState();
    /**
     * Update last state ( should be call after render )
     */

    void updatelastKeyState();
};
