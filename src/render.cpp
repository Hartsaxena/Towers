/*
This file contains methods that render all objects in the game. Calculations for updating positions of objects, and the like, are done in the update.c file. Game updates and rendering should be done separately.
*/
#include <SDL2\\SDL.h>

#include "front.hpp"
#include "render.hpp"


void render_FillScreenColor(SDL_Renderer* renderer, Color color)
{
    // Fills the screen with a color.
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.alpha);
    SDL_RenderClear(renderer);
}


void render_BlankScreen(SDL_Renderer* renderer)
{
    // Fills the screen with black.
    Color color = (Color) {.r = 0, .g = 0, .b = 0, .alpha = 255};
    render_FillScreenColor(renderer, color);
}


void render_DrawRect(SDL_Renderer* renderer, Rectangle* rect)
{
    Color color = rect->color;
    SDL_RenderDrawRect(renderer, &rect->rect);
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.alpha);
    SDL_RenderFillRect(renderer, &rect->rect);
}