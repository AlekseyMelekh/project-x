#include "pch.h"

#include "Main.h"

bool App::Init() 
{

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cout << "ERROR: " << SDL_GetError() << "\n";
		return false;
	}

	Window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WWIDTH, WHEIGHT, SDL_WINDOW_SHOWN);
	if (Window == nullptr) {
		std::cout << SDL_GetError() << std::endl;
		return false;
	}

	/*Uint32 FullscreenFlag = SDL_WINDOW_FULLSCREEN;
	bool IsFullscreen = SDL_GetWindowFlags(Window) & FullscreenFlag;
	SDL_SetWindowFullscreen(Window, IsFullscreen ? 0 : FullscreenFlag);*/ /// FOR FULLSCREEN

	Generator();

	renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr) {
		std::cout << SDL_GetError() << std::endl;
		return false;
	}

	background = LoadImage("Pictures/background.bmp", renderer);
	if (background == nullptr) {
		std::cout << SDL_GetError() << std::endl;
		return false;
	}

	if (Hero.OnLoad("Pictures/yoshi.bmp", renderer, EntityWidht, EntityHeight, 8) == false) {
		return false;
	}

	Hero.X = 0, Hero.Y = -15;

	App::Game_Map.OnLoad("Maps/1.map", renderer);

	return true;
}