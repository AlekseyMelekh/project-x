#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <cmath>
#include <map>

#include "Define.h"
#include "Texture.h"
#include "Events.h"
#include "Animation.h"
#include "Entity.h"
#include "Camera.h"
#include "Map.h"
#include "MainHero.h"
#include "Motion.h"
#include "AgressiveNPC.h"
#include "Instruments.h"
#include "Interface.h"

class App : public Events{
private:
	std::vector<AgressiveNPC>			Agr_NPC;
private:
	Animation							Anim_Yoshi;
	bool Running;
	int timeCounter;
	SDL_Window*							Window;
	SDL_Texture*						background;
	SDL_Renderer*						renderer;
	std::map < std::string, bool >		flags;
	Instruments							instr;
	HealthBar							HPbar;
public:
	static Map							Game_Map;
	static MainHero						Hero;
public:
	App();
	~App() {};
	bool Init(); // Ду
	void onEvent(SDL_Event* Event); // Функция, отвечаеющая на действие игрока
	void Loop(); // Подготавливает данные для рендеринга, после какого-то ивента(обновляет ХП, местоположение мобов)
	void Render(); // Из названия понятно
	void OnExit(); // Выйди и зайди нормально
	void Generator(); // Генератор ы
	void OnKeyDown(SDL_Keycode sym, int mod, int unicode);
	void OnKeyUp(SDL_Keycode sym, int mod, int unicode);
	void Cleanup(); // Очистить все, что мы загрузили(изображения, карты и тд и тп)
	int StartGame(); // Покажите мне дауна, который не поймет, что здесь написано
	void CheckFlags();
	void startTimer();
	Uint32 getDiff();
};