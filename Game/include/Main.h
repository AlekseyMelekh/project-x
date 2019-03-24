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
	bool Init(); // ��
	void onEvent(SDL_Event* Event); // �������, ����������� �� �������� ������
	void Loop(); // �������������� ������ ��� ����������, ����� ������-�� ������(��������� ��, �������������� �����)
	void Render(); // �� �������� �������
	void OnExit(); // ����� � ����� ���������
	void Generator(); // ��������� �
	void OnKeyDown(SDL_Keycode sym, int mod, int unicode);
	void OnKeyUp(SDL_Keycode sym, int mod, int unicode);
	void Cleanup(); // �������� ���, ��� �� ���������(�����������, ����� � �� � ��)
	int StartGame(); // �������� ��� �����, ������� �� ������, ��� ����� ��������
	void CheckFlags();
	void startTimer();
	Uint32 getDiff();
};