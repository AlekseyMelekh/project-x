#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <iostream>

SDL_Texture* LoadImage(std::string, SDL_Renderer *);
void DrawTexture(int x, int y, SDL_Texture *, SDL_Renderer *);
bool DrawTexture(SDL_Texture* tex, SDL_Renderer* rend, int X, int Y, int X2, int Y2, int W, int H);