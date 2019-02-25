#pragma once

#include <SDL.h>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

#include "Tile.h"
#include "Texture.h"

class Map {
public:
	int Width = MAP_WBLOCK;
	int Height = MAP_HBLOCK;

	std::vector< std::vector<Tile> > MAP;
	SDL_Texture* Tiles_Textures;

	Map();

	bool OnLoad(std::string File, SDL_Renderer* renderer);

	void OnRender(SDL_Renderer* renderer, int MapX, int MapY);

	void OnCleanup();
};