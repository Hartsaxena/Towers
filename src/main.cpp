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

    // Initializing Frontend Variables
    FrontendManager front;
    InputManager input;
    Canvas gameRenderer(front.renderer);

    // Initializing Game Variables
    Rectangle testRectangle = (Rectangle)
    {.rect = (SDL_Rect) {.x = 100, .y = 100, .w = 33,  .h = 33},
     .color = (Color)   {.r = 255, .g = 0,   .b = 0,   .alpha = 255}};


    std::cout<<"Finished Loading! Starting Game Loop\n\n"; // Separate game errors from initializing errors.

    // Actual Game Loop
    bool IsRunning = true;
    while (IsRunning) {

        // Handle Input Events
        IsRunning = input.HandleInputs();

        // Update code here

        /*
        Some filler movement code for a rectangle.
        This isn't meant for the final game, just for testing the input manager.
        */
        int cubeSpeed = 3;
        if (input.inputKeys[SDL_SCANCODE_W])
            testRectangle.rect.y -= cubeSpeed;
        if (input.inputKeys[SDL_SCANCODE_S])
            testRectangle.rect.y += cubeSpeed;
        if (input.inputKeys[SDL_SCANCODE_A])
            testRectangle.rect.x -= cubeSpeed;
        if (input.inputKeys[SDL_SCANCODE_D])
            testRectangle.rect.x += cubeSpeed;
        
        // Boundary Checking
        if (testRectangle.rect.x < 0)
            testRectangle.rect.x = 0;
        if (testRectangle.rect.y < 0)
            testRectangle.rect.y = 0;
        if (testRectangle.rect.x + testRectangle.rect.w > front_SCREENX)
            testRectangle.rect.x = front_SCREENX - testRectangle.rect.w;
        if (testRectangle.rect.y + testRectangle.rect.h > front_SCREENY)
            testRectangle.rect.y = front_SCREENY - testRectangle.rect.h;

        // Rendering Code Here
        gameRenderer.BlankScreen();
        gameRenderer.DrawRect(&testRectangle);

        front.PresentRenderer();
        front.PauseDelay();
    }

    // Quitting the game
    return 0;
}