#pragma once

#include <SDL.h>
#include <SDL_ttf.h>

class Instruments {
public:
	TTF_Font* FontLeadCoat;
	SDL_Color ColorWhite;
	Instruments() {
		if (TTF_Init() == -1) {
			printf("TTF_Init: %s\n", TTF_GetError());
		}
		FontLeadCoat = TTF_OpenFont("Pictures/leadcoat.ttf", 24);
		if (!FontLeadCoat) {
			printf("TTF_OpenFont: %s\n", TTF_GetError());
		}
		ColorWhite = { 255, 255, 255 };
	}
	void OnCleanup() {
	};
};