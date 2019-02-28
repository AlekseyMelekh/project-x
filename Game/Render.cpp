#include "pch.h"

#include "Main.h"

void App::Render()
{
	SDL_RenderClear(renderer);

	int bW, bH;
	SDL_QueryTexture(background, NULL, NULL, &bW, &bH);

	for (int i = 0; i < ceil(1.0*WWIDTH / bW); ++i)
	{
		for (int j = 0; j < ceil(1.0*WHEIGHT / bH); ++j)
		{
			DrawTexture(i * bW, j * bH, background, renderer);
		}
	}

	float tmpX = WWIDTH / TILE_SIZE / 2, tmpY = WHEIGHT / TILE_SIZE / 2;
	//std::cout << std::setprecision(5) << Hero.X - tmpX << ' ' << Hero.Y - tmpY << '\n';
	Camera::CameraControl.SetPos(Hero.X - tmpX, Hero.Y - tmpY);
	App::Game_Map.OnRender(renderer, Camera::CameraControl.GetX(), Camera::CameraControl.GetY());

	for (int i = 0; i < Entity::EntityList.size(); i++) {
		if (!Entity::EntityList[i]) continue;

		Entity::EntityList[i]->OnRender(renderer);
	}

	Hero.OnRender(renderer);
	SDL_RenderPresent(renderer);
	SDL_Delay(30);
}