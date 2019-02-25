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
	bool Init(); // ��� ������� �����, ����� ������ ��������� ��������� ����(��������: ���������� ���������)
	void onEvent(SDL_Event* Event); // �������, ����������� �� �������� ������
	void Loop(); // �������������� ������ ��� ����������, ����� ������-�� ������(��������� ��, �������������� �����)
	void Render(); // �� �������� �������
	void OnExit(); // ����� � ����� ���������
	void Generator(); // ��������� �
	void OnKeyDown(SDL_Keycode sym, int mod, int unicode); // ���������� �������
	void Cleanup(); // �������� ���, ��� �� ���������(�����������, ����� � �� � ��)
	int StartGame(); // �������� ��� �����, ������� �� ������, ��� ����� ��������
	void startTimer();
	Uint32 getDiff();
};