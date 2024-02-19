/*
This file contains methods that manage the SDL2 library, which is used as the frontend of the game. This includes window creation, rendering, and event handling.
*/
#include <iostream>
#include <SDL2\\SDL.h>

#include "front.hpp"



FrontendManager::FrontendManager()
{
    /*
    This function initializes the SDL2 library. It creates a window and renderer, and returns 0 if successful, or -1 if not.
    */
  
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) { // Initialize SDL
        std::cout<<"Failed to initialize SDL.\n";
        std::cout<<SDL_GetError();
        SDL_Quit();
        exit(1);
    }

    this->window = SDL_CreateWindow(front_WINDOWTITLE,
                                    SDL_WINDOWPOS_UNDEFINED,
                                    SDL_WINDOWPOS_UNDEFINED,
                                    front_SCREENX, front_SCREENY,
                                    SDL_WINDOW_SHOWN);
    if (this->window == NULL) {
        std::cout<<"FATAL ERROR: Window could not be displayed.\n";
        std::cout<<SDL_GetError();
        SDL_Quit();
        exit(1); // Quit the program
    }
    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
    this->winRect = (SDL_Rect)
    {.x = 0, .y = 0,
     .w = front_SCREENX, .h = front_SCREENY};
}


FrontendManager::~FrontendManager()
{
    /*
    Destructor for the FrontendManager class.
    Quits SDL2 and frees memory.
    */
    if (this->window != NULL) {
        SDL_DestroyWindow(this->window);
        SDL_DestroyRenderer(this->renderer);
    }
    SDL_Quit();
}


void FrontendManager::PresentRenderer()
{
    /*
    This function presents the renderer to the window.
    */
    SDL_RenderPresent(this->renderer);
}

void FrontendManager::PauseDelay()
{
    /*
    This function pauses the game for a short time, to limit the frame rate.
    */
    SDL_Delay(front_FRAMEPAUSEDELAY);
}



InputManager::InputManager()
{
    /*
    Constructor for the InputManager class.
    */

    for (int i = 0; i < 286; i++)
        this->inputKeys[i] = false;

    this->inputEvent = new SDL_Event;
    if (this->inputEvent == NULL) {
        std::cout<<"Failed to allocate memory for input event data.\n";
        exit(1);
    }
    
    front_MouseState* MouseState = new front_MouseState;
    if (MouseState == NULL) {
        std::cout<<"Failed to allocate memory for Mouse State data.\n";
        exit(1);
    }
   
    for (int i = 0; i < 5; i++)
        MouseState->ButtonStates[i] = false;
    MouseState->x = 0;
    MouseState->y = 0;

    this->mouseState = MouseState;
}


InputManager::~InputManager()
{
    /*
    Destructor for the InputManager class.
    Frees memory.
    */
    delete this->inputEvent;
    delete this->mouseState;
}


bool InputManager::HandleInputs()
{
    /*
    This function handles all input events. It returns true if the game should continue running, false if it should quit.
    */
    bool IsRunning = true;
    while (SDL_PollEvent(this->inputEvent) > 0) {
        switch (inputEvent->type) {
            case SDL_KEYDOWN: {
                this->inputKeys[inputEvent->key.keysym.scancode] = true;
                break;
            }
            case SDL_KEYUP: {
                this->inputKeys[inputEvent->key.keysym.scancode] = false;
                break;
            }
            
            case SDL_MOUSEBUTTONDOWN: {
                this->mouseState->ButtonStates[inputEvent->button.button] = true;
                break;
            }
            case SDL_MOUSEBUTTONUP: {
                this->mouseState->ButtonStates[inputEvent->button.button] = false;
                break;
            }
            case SDL_MOUSEMOTION: {
                this->mouseState->x = inputEvent->motion.x;
                this->mouseState->y = inputEvent->motion.y;
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