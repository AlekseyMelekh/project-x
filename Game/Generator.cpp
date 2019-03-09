#include "pch.h"

#include <iostream>
#include <fstream>
#include "Main.h"

void App::Generator()
{
	srand(time(NULL));
	FILE *kek = fopen("Maps/1.map", "w");

	int type[MAP_WBLOCK][MAP_HBLOCK];
	int text[MAP_WBLOCK][MAP_HBLOCK];

	for (int i = 0; i < MAP_WBLOCK; ++i){
		for (int j = 0; j < MAP_HBLOCK; ++j){
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
