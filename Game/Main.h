#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "Define.h"
#include "Surface.h"

class App {
private:
	bool Running;
	SDL_Window	*Window;
	SDL_Surface *Window_surface;
	SDL_Surface *Surf_Test;
public:
	App();
	~App() {};
	bool Init(); // Эта функция нужна, чтобы задать начальные настройки мира(например: заспавнить персонажа)
	void Event(SDL_Event *); // Функция, отвечаеющая на действие игрока
	void Loop(); // Подготавливает данные для рендеринга, после какого-то ивента(обновляет ХП, местоположение мобов)
	void Render(); // Из названия понятно
	void Cleanup(); // Очистить все, что мы загрузили(изображения, карты и тд и тп)
	int StartGame(); // Покажите мне дауна, который не поймет, что здесь написано
};