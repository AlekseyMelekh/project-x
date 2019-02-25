#include "pch.h"

#include "Map.h"

Map::Map() {
	Tiles_Textures = nullptr;
	Width = Height = 0;
}

bool Map::OnLoad(std::string File, SDL_Renderer* renderer)
{
	Tiles_Textures = LoadImage("D:/Projects/University/Game/Pictures/MAP_TILES.bmp", renderer);
	if (Tiles_Textures == nullptr) {
		std::cout << SDL_GetError() << std::endl;
		return false;
	}

	FILE* FileMap = fopen(File.c_str(), "r");

	if (FileMap == NULL) {
		std::cout << "Can't open File with Map\n";
		return false;
	}

	MAP.resize(MAP_WBLOCK);

	for (int i = 0; i < MAP_WBLOCK; ++i)
	{
		MAP[i].resize(MAP_HBLOCK);
		for (int j = 0; j < MAP_HBLOCK; ++j)
		{
			fscanf(FileMap, "%d:%d ", &MAP[i][j].TextureID, &MAP[i][j].TypeID);
		}
	}

	fclose(FileMap);
	return true;
}

void Map::OnRender(SDL_Renderer* renderer, int MapX, int MapY)
{
	for (int X = MapX * TILE_SIZE; X < MapX * TILE_SIZE + WWIDTH + TILE_SIZE; X += TILE_SIZE)
	{
		for (int Y = MapY * TILE_SIZE; Y < MapY * TILE_SIZE + WHEIGHT + TILE_SIZE; Y += TILE_SIZE)
		{
			int curX = X / TILE_SIZE;
			int curY = Y / TILE_SIZE;
			int X1 = (curX - MapX) * TILE_SIZE;
			int Y1 = (curY - MapY) * TILE_SIZE;
			if(curX < MAP_WBLOCK && curY < MAP_HBLOCK && curX >= 0 && curY >= 0 && MAP[curX][curY].TypeID != TILE_TYPE_NONE)
				DrawTexture(Tiles_Textures, renderer, X1, Y1, 0, MAP[curX][curY].TextureID * 64, 64, 64);
		}
	}
}

void Map::OnCleanup()
{
	SDL_DestroyTexture(Tiles_Textures);
}