#include "pch.h"

#include "Surface.h"

Surface::Surface() {
}

SDL_Surface* Surface::Load(char* File, SDL_PixelFormat *fmt)
{
	SDL_Surface* Surf_Temp = NULL;
	SDL_Surface* Surf_Return = NULL;

	if ((Surf_Temp = IMG_Load(File)) == NULL) 
	{
		std::cout << "ERROR: " << IMG_GetError() << "\n";
		return NULL;
	}

	Surf_Return = SDL_ConvertSurface(Surf_Temp, fmt, 0);
	SDL_FreeSurface(Surf_Temp);

	return Surf_Return;
}

bool Surface::Draw(SDL_Window* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y) {
	if (Surf_Dest == NULL || Surf_Src == NULL) 
	{
		return false;
	}

	SDL_Rect DestR;

	DestR.x = X;
	DestR.y = Y;

	SDL_BlitSurface(Surf_Src, NULL, Surf_Dest, &DestR);

	return true;
}