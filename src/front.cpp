/*
This file contains methods that manage the SDL2 library, which is used as the frontend of the game. This includes window creation, rendering, and event handling.
*/
#include <iostream>
#include <SDL2\\SDL.h>

#include "front.hpp"


SDL_Window* front_Window;
SDL_Renderer* front_Renderer;
SDL_Rect front_WinRect = {0, 0, front_SCREENX, front_SCREENY};


void front_Quit()
{
    /*
    This function quits the SDL2 library and the program as a whole.
    */
    if (front_Window != NULL) {
        SDL_DestroyWindow(front_Window);
        SDL_DestroyRenderer(front_Renderer);
    }
    SDL_Quit();
    exit(0);
}


int front_Init()
{
    /*
    This function initializes the SDL2 library. It creates a window and renderer, and returns 0 if successful, or -1 if not.
    */
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) { // Initialize SDL
        std::cout<<"Failed to initialize SDL.\n";
        std::cout<<SDL_GetError();
        return -1;
    }

    front_Window = SDL_CreateWindow(front_WINDOWTITLE,
                                    SDL_WINDOWPOS_UNDEFINED,
                                    SDL_WINDOWPOS_UNDEFINED,
                                    front_SCREENX, front_SCREENY,
                                    SDL_WINDOW_SHOWN);
    if (front_Window == NULL) {
        std::cout<<"FATAL ERROR: Window could not be displayed.\n";
        return -1;
    }
    front_Renderer = SDL_CreateRenderer(front_Window, -1, SDL_RENDERER_ACCELERATED);

    return 0;
}


front_MouseState* front_InitMouseState()
{
    /*
    This function creates and initializes a MouseState struct.
    */

    front_MouseState* MouseState = new front_MouseState;
    if (MouseState == NULL) {
        std::cout<<"Failed to allocate memory for Mouse State data.\n";
        front_Quit();
    }
   
    for (int i = 0; i < 5; i++)
        MouseState->ButtonStates[i] = false;
    MouseState->x = 0;
    MouseState->y = 0;

    return MouseState;
}


bool front_HandleInputs(SDL_Event* inputEvent, bool inputKeys[286], front_MouseState* mouseState)
{
    /*
    This function handles all input events. It returns true if the game should continue running, false if it should quit.
    */
    bool IsRunning = true;
    while (SDL_PollEvent(inputEvent) > 0) {
        switch (inputEvent->type) {
            case SDL_KEYDOWN: {
                inputKeys[inputEvent->key.keysym.scancode] = true;
                break;
            }
            case SDL_KEYUP: {
                inputKeys[inputEvent->key.keysym.scancode] = false;
                break;
            }
            
            case SDL_MOUSEBUTTONDOWN: {
                mouseState->ButtonStates[inputEvent->button.button] = true;
                break;
            }
            case SDL_MOUSEBUTTONUP: {
                mouseState->ButtonStates[inputEvent->button.button] = false;
                break;
            }
            case SDL_MOUSEMOTION: {
                mouseState->x = inputEvent->motion.x;
                mouseState->y = inputEvent->motion.y;
                break;
            }

            case SDL_QUIT: {
                IsRunning = false;
                break;
            }
            default: {
                break;
            }
        }
    }
    return IsRunning;
}