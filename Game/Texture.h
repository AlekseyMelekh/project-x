#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <iostream>

SDL_Texture* LoadImage(std::string, SDL_Renderer *);
void DrawTexture(float x, float y, SDL_Texture *, SDL_Renderer *);
bool DrawTexture(SDL_Texture* tex, SDL_Renderer* rend, float X, float Y, float X2, float Y2, float W, float H);