#include "pch.h"

#include "Main.h"

void App::Cleanup()
{
	for (int i = 0; i < Entity::EntityList.size(); i++) {
		if (!Entity::EntityList[i]) continue;

		Entity::EntityList[i]->OnCleanup();
	}
	Entity::EntityList.clear();
	Hero.OnCleanup();
	Game_Map.OnCleanup();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(background);
	SDL_DestroyWindow(Window);
	SDL_Quit();
}
