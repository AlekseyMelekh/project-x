#include "pch.h"
#include "Interface.h"

void HealthBar::OnRender(SDL_Renderer* renderer) {
	DrawText(renderer, tools.ColorWhite, tools.FontLeadCoat, std::to_string(HP), WWIDTH - 100, 0, 100, 100);
}

void HealthBar::OnLoop(const int _HP) {
	ChangeHP(_HP);
}