/*
Driver file.
*/

#include <iostream>
#include <string>
#include <SDL2\\SDL.h>

#include "front.hpp"
#include "render.hpp"


int main(int argc, char* argv[])
{
    // Initializing SDL
    std::cout<<"Loading...\n";
    if (front_Init() != 0) {
        std::cout<<"Failed to initialize SDL.\n";
        front_Quit();
    }

    // Initializing Frontend Variables
    SDL_Event inputEvent;
    bool inputKeys[286]; // Contains bools for all SDL scancodes. true = key is pressed, false = key isn't pressed.
    for (int i = 0; i < 286; i++) { // Init them all to false first
        inputKeys[i] = false;
    }

    // Contains the state of the mouse, including buttons and position.
    front_MouseState* mouseState = front_InitMouseState();


    // Initializing Game Variables
    Rectangle testRectangle = (Rectangle) {.rect = (SDL_Rect) {.x = 100, .y = 100, .w = 400, .h = 600},
                                            .color = (Color) {.r = 255, .g = 0, .b = 0, .alpha = 255}};


    std::cout<<"Finished Loading! Starting Game Loop\n\n"; // Separate game errors from initializing errors.
    
    // Actual Game Loop
    bool IsRunning = true;
    while (IsRunning) {

        // Handle Input Events
        IsRunning = front_HandleInputs(&inputEvent, inputKeys, mouseState);

        // Update code here

        // Rendering Code Here
        render_BlankScreen(front_Renderer);
        render_DrawRect(front_Renderer, &testRectangle);

        SDL_RenderPresent(front_Renderer);
        SDL_Delay(front_FRAMEPAUSEDELAY);
    }

    front_Quit();
    return 0;
}