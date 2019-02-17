#pragma once

#include <SDL.h>
#include <SDL_image.h>

class Surface {
public:

	Surface();

	static SDL_Surface* Load(char* File, SDL_PixelFormat *fmt);
	static bool Draw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y);

};