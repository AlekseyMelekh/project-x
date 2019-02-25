#include "pch.h"

#include "Main.h"

void App::Render()
{
	SDL_RenderClear(renderer);
	
	/*Uint32 FullscreenFlag = SDL_WINDOW_FULLSCREEN;
	bool IsFullscreen = SDL_GetWindowFlags(Window) & FullscreenFlag;
	SDL_SetWindowFullscreen(Window, IsFullscreen ? 0 : FullscreenFlag);*/ ///for FullScreen

	int bW, bH;
	SDL_QueryTexture(background, NULL, NULL, &bW, &bH);

	for (int i = 0; i < ceil(1.0*WWIDTH / bW); ++i)
	{
		for (int j = 0; j < ceil(1.0*WHEIGHT / bH); ++j)
		{
			DrawTexture(i * bW, j * bH, background, renderer);
		}
	}
	Game_Map.OnRender(renderer, Camera::CameraControl.GetX(), Camera::CameraControl.GetY());
	for (int i = 0; i < Entity::EntityList.size(); i++) {
		if (!Entity::EntityList[i]) continue;

		Entity::EntityList[i]->OnRender(renderer);
	}

	Hero.X = WWIDTH / 2;
	Hero.Y = WHEIGHT / 2;
	Hero.OnRender(renderer);
 
	SDL_RenderPresent(renderer);
	SDL_Delay(100);
}