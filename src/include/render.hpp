#pragma once

#include <SDL2\\SDL.h>

typedef struct Color {
    int r, g, b, alpha;
} Color;

typedef struct Rectangle {
    SDL_Rect rect;
    Color color;
} Rectangle;

class Canvas
{
/*
The purpose of this class is to manage the rendering of the game.
*/

SDL_Renderer* renderer;

public:

    explicit Canvas(SDL_Renderer* renderer);
    ~Canvas();

    void FillScreenColor(Color color);
    void BlankScreen();
    void DrawRect(Rectangle* rect);
};