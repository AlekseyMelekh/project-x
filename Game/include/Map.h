#pragma once

#include <SDL.h>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <iomanip>

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

	void OnRender(SDL_Renderer* renderer, partOfDay, float MapX, float MapY);

	void OnCleanup();
};