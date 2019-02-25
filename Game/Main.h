#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <cmath>

#include "Define.h"
#include "Texture.h"
#include "Events.h"
#include "Animation.h"
#include "Entity.h"
#include "Camera.h"
#include "Map.h"
#include "MainHero.h"

class App : public Events{
private:
	Entity				Entity1;
	Entity				Entity2;
	MainHero			Hero;
private:
	Animation			Anim_Yoshi;
	bool Running;
	int timeCounter;
	SDL_Window*			Window;
	SDL_Texture*		background;
	SDL_Renderer*		renderer;
	Map					Game_Map;
public:
	App();
	~App() {};
	bool Init(); // Эта функция нужна, чтобы задать начальные настройки мира(например: заспавнить персонажа)
	void onEvent(SDL_Event* Event); // Функция, отвечаеющая на действие игрока
	void Loop(); // Подготавливает данные для рендеринга, после какого-то ивента(обновляет ХП, местоположение мобов)
	void Render(); // Из названия понятно
	void OnExit(); // Выйди и зайди нормально
	void Generator(); // Генератор ы
	void OnKeyDown(SDL_Keycode sym, int mod, int unicode); // управление камерой
	void Cleanup(); // Очистить все, что мы загрузили(изображения, карты и тд и тп)
	int StartGame(); // Покажите мне дауна, который не поймет, что здесь написано
	void startTimer();
	Uint32 getDiff();
};