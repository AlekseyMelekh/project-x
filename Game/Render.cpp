#include "pch.h"

#include "Main.h"

void App::Render()
{
	Surface::Draw(Window, Surf_Test, 0, 0);

	SDL_Flip(Surf_Display);
}