#pragma once

#include <SDL2\\SDL.h>

typedef struct Color {
    int r, g, b, alpha;
} Color;

typedef struct Rectangle {
    SDL_Rect rect;
    Color color;
} Rectangle;

void render_FillScreenColor(SDL_Renderer* renderer, Color color);
void render_BlankScreen(SDL_Renderer* renderer);
void render_DrawRect(SDL_Renderer* renderer, Rectangle* rect);