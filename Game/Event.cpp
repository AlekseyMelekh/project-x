#include "pch.h"

#include "Main.h"

void App::Event(SDL_Event* Cur_Event)
{
	if (Cur_Event->type == SDL_QUIT) 
	{
		Running = false;
	}
}