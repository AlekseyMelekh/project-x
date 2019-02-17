#include "pch.h"

#include "Main.h"

bool App::Init() 
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cout << "ERROR: " << SDL_GetError() << "\n";
		return false;
	}

	Window = SDL_CreateWindow("Game", 100, 100, WWIDTH, WHEIGHT, SDL_WINDOW_SHOWN);

	if (Window == nullptr)
	{
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << "\n";
		return false;
	}

	Window_surface = SDL_GetWindowSurface(Window);
	char path[] = "D:/Projects/University/Game/Pictures/background.bmp";

	if ((Surf_Test = Surface::Load(path, Window_surface->format)) == NULL)
	{
		return false;
	}

	return true;
}