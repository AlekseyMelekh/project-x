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

void DrawTexture(float x, float y, SDL_Texture* tex, SDL_Renderer* rend)
{
	SDL_Rect pos;

	pos.x = x, pos.y = y;

	SDL_QueryTexture(tex, NULL, NULL, &pos.w, &pos.h);
	SDL_RenderCopy(rend, tex, NULL, &pos);
}

bool DrawTexture(SDL_Texture* tex, SDL_Renderer* rend, float X, float Y, float X2, float Y2, float W, float H)
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

void DrawText(SDL_Renderer* rend, SDL_Color color, TTF_Font* font, std::string text, float X, float Y, float width, float height) {
	
	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, text.c_str(), color); 
	SDL_Texture* Message = SDL_CreateTextureFromSurface(rend, surfaceMessage); 
	SDL_Rect Message_rect;
	Message_rect.x = X;  
	Message_rect.y = Y; 
	Message_rect.w = width; 
	Message_rect.h = height;
	SDL_RenderCopy(rend, Message, NULL, &Message_rect);
	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(Message);
}