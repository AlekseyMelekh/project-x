#include "pch.h"

#include "Main.h"

void App::Cleanup()
{
	SDL_FreeSurface(Window_surface);
	SDL_FreeSurface(Surf_Test);
	SDL_DestroyWindow(Window);
	SDL_Quit();
}
