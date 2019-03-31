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
			DrawTexture(i * bW, j * bH, background, renderer, Game_time.GetPart());
		}
	}

	float tmpX = WWIDTH / TILE_SIZE / 2, tmpY = WHEIGHT / TILE_SIZE / 2;

	if (Game_time.GetPart() == NIGHT) {
		std::cout << "NIGHT\n";
	}
	else {
		std::cout << "DAY\n";
	}

	Camera::CameraControl.SetPos(Hero.X - tmpX, Hero.Y - tmpY);
	App::Game_Map.OnRender(renderer, Game_time.GetPart(), Camera::CameraControl.GetX(), Camera::CameraControl.GetY());

	for (int i = 0; i < NUM_AGR_NPC; ++i) {
		Agr_NPC[i].OnRender(renderer, Game_time.GetPart(), Camera::CameraControl.GetX(), Camera::CameraControl.GetY());
	}

	Hero.OnRender(renderer, Game_time.GetPart());
	HPbar.OnRender(renderer);
	if (Hero.HP <= 0) {
		Running = 0;
		SDL_Texture* you_died = LoadImage("Pictures/you_died.bmp", renderer);
		DrawTexture(you_died, renderer, 0, 0, 0, 0, WWIDTH, WHEIGHT, NONE_PART);
		SDL_DestroyTexture(you_died);
		SDL_RenderPresent(renderer);
		SDL_Delay(5000);
	}
	
	SDL_RenderPresent(renderer);
	SDL_Delay(1);
}