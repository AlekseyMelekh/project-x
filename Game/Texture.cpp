#include "pch.h"

#include "Texture.h"

SDL_Texture* LoadImage(std::string file, SDL_Renderer* renderer) {
	SDL_Surface *loadedImage = nullptr;
	SDL_Texture *texture = nullptr;
	loadedImage = IMG_Load(file.c_str());
	if (loadedImage != nullptr) {
		texture = SDL_CreateTextureFromSurface(renderer, loadedImage);
		SDL_FreeSurface(loadedImage);
	}
	else {
		std::cout << SDL_GetError() << std::endl;
		return nullptr;
	}
	return texture;
}

void DrawTexture(int x, int y, SDL_Texture* tex, SDL_Renderer* rend)
{
	SDL_Rect pos;

	pos.x = x, pos.y = y;

	SDL_QueryTexture(tex, NULL, NULL, &pos.w, &pos.h);
	SDL_RenderCopy(rend, tex, NULL, &pos);
}

bool DrawTexture(SDL_Texture* tex, SDL_Renderer* rend, int X, int Y, int X2, int Y2, int W, int H)
{
	if (tex == NULL || rend == NULL) {
		return false;
	}

	SDL_Rect DestR;

	DestR.x = X;
	DestR.y = Y;
	DestR.h = H;
	DestR.w = W;

	SDL_Rect SrcR;

	SrcR.x = X2;
	SrcR.y = Y2;
	SrcR.w = W;
	SrcR.h = H;

	SDL_RenderCopy(rend, tex, &SrcR, &DestR);

	return true;
}