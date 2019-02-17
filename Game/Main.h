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
	bool Init(); // ��� ������� �����, ����� ������ ��������� ��������� ����(��������: ���������� ���������)
	void Event(SDL_Event *); // �������, ����������� �� �������� ������
	void Loop(); // �������������� ������ ��� ����������, ����� ������-�� ������(��������� ��, �������������� �����)
	void Render(); // �� �������� �������
	void Cleanup(); // �������� ���, ��� �� ���������(�����������, ����� � �� � ��)
	int StartGame(); // �������� ��� �����, ������� �� ������, ��� ����� ��������
};