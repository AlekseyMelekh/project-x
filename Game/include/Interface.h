#pragma once

#include "Instruments.h"
#include "Texture.h"
#include "Define.h"

class HealthBar {
private:
	int HP;
	Instruments tools;
public:

	HealthBar() { HP = 100; };

	void ChangeHP(int _HP) {
		HP = _HP;
	};

	void OnLoop(const int);
	void OnRender(SDL_Renderer* renderer);
	void OnCleanup();
};