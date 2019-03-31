#include "pch.h"

#include "Map.h"

Map::Map() {
	Tiles_Textures = nullptr;
	Width = Height = 0;
}

bool Map::OnLoad(std::string File, SDL_Renderer* renderer)
{
	Tiles_Textures = LoadImage("Pictures/MAP_TILES.bmp", renderer);
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

void Map::OnRender(SDL_Renderer* renderer, partOfDay part, float MapX, float MapY)
{
	//std::cout << std::setprecision(5) << MapX << ' ' << MapY << '\n';
	for (float X = MapX; X <= MapX + WWIDTH / TILE_SIZE; ++X)
	{
		for (float Y = MapY; Y <= MapY + WHEIGHT / TILE_SIZE; ++Y)
		{
			int curX = X;
			int curY = Y;
			float X1 = (curX - MapX) * TILE_SIZE;
			float Y1 = (curY - MapY) * TILE_SIZE;
			if (curX < MAP_WBLOCK && curY < MAP_HBLOCK && curX >= 0 && curY >= 0 && MAP[curX][curY].TypeID != TILE_TYPE_NONE) {
				DrawTexture(Tiles_Textures, renderer, X1, Y1, 0, MAP[curX][curY].TextureID * TILE_SIZE, TILE_SIZE, TILE_SIZE, part);
			}
		}
	}
}

void Map::OnCleanup()
{
	SDL_DestroyTexture(Tiles_Textures);
}