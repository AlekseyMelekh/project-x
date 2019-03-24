#include "pch.h"

#include <iostream>
#include <fstream>
#include "Main.h"

void App::Generator()
{
	srand(time(NULL));
	FILE *kek = fopen("Maps/1.map", "w");

	std::vector< std::vector<int> > type(MAP_WBLOCK, std::vector<int>(MAP_HBLOCK));
	std::vector< std::vector<int> > text(MAP_WBLOCK, std::vector<int>(MAP_HBLOCK));

	for (int i = 0; i < MAP_WBLOCK; ++i){
		for (int j = 0; j < MAP_HBLOCK; ++j){
			if (i == 0 || i == MAP_WBLOCK - 1) {
				type[i][j] = TILE_TYPE_BLOCK;
				text[i][j] = TILE_TEXT_BRICK;
				continue;
			}
			if (j < 15) {
				type[i][j] = TILE_TYPE_NONE;
				text[i][j] = TILE_TEXT_NONE;
			}
			else {
				if (type[i][j-1] != TILE_TYPE_BLOCK) {
					if (rand() & 1) {
						type[i][j] = TILE_TYPE_BLOCK;
						text[i][j] = TILE_TEXT_BRICK;
					}
					else {
						type[i][j] = TILE_TYPE_NONE;
						text[i][j] = TILE_TEXT_NONE;
					}
				}
				else {
					type[i][j] = TILE_TYPE_BLOCK;
					text[i][j] = TILE_TEXT_BRICK;
				}
			}
		}
	}
	for (int i = 0; i < MAP_WBLOCK; ++i) {
		for (int j = 0; j < MAP_HBLOCK; ++j) {
			fprintf(kek, "%d:%d ", text[i][j], type[i][j]);
		}
		fprintf(kek, "\n");
	}
	fclose(kek);
}
