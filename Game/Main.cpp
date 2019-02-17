#include "pch.h"

#include "Main.h"

App::App()
{
	Window = NULL;
	Window_surface = Surf_Test = NULL;
	Running = true;
}

int App::StartGame()
{
	if (!Init())
	{
		return -1;
	}

	SDL_Event Cur_Event;

	while (Running)
	{
		while (SDL_PollEvent(&Cur_Event))
		{
			Event(&Cur_Event);
		}
		Loop();
		Render();
	}

	Cleanup();

	return 0;
}

int main(int argc, char* argv[])
{
	App game;

	return game.StartGame();
}