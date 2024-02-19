#pragma once

#include <SDL2\\SDL.h>

#define front_SCREENX 1000
#define front_SCREENY 1000

#define front_FPS 60
#define front_FRAMEPAUSEDELAY (1000 / front_FPS)

#define front_WINDOWTITLE "TOWERS"

typedef struct front_MouseState {
    bool ButtonStates[5];
    int x, y;
} front_MouseState;


// Forward declarations of classes so that they can reference each other.
class FrontendManager;
class InputManager;


class InputManager
{
/*
The purpose of this class is to manage inputs of the game.
*/

public:
    bool inputKeys[286];

    SDL_Event* inputEvent;
    front_MouseState* mouseState;

    InputManager();
    ~InputManager();

    bool HandleInputs();
    front_MouseState* InitMouseState();
};


class FrontendManager
{
/*
The purpose of this class is to manage the frontend of the game.
*/

public:
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Rect winRect;

    FrontendManager();
    ~FrontendManager();

    void PresentRenderer();
    void PauseDelay();
};
