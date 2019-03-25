#include "pch.h"

#include <iostream>
#include <fstream>
#include "Main.h"
#include <random>

int countAliveNeighbours(int &x, int &y, std::vector< std::vector<int> >& type) {
	int dx[8] = { 1, 1, 1,-1, -1,-1, 0, 0 };
	int dy[8] = { 0,-1, 1, 0, -1, 1, 1,-1 };
	int count = 0;

	for (int i = 0; i < 8; ++i) {
		int cx = x + dx[i], cy = y + dy[i];
		if (cx >= MAP_WBLOCK || cy >= MAP_HBLOCK || cy < 0 || cx < 0) {
			count++;
		}
		else {
			if (type[cx][cy] == TILE_TYPE_BLOCK) {
				count++;
			}
		}
	}
	
	return count;
}

void doSimulationStep(std::vector< std::vector<int> >& type, const int& deathLimit, const int& birthLimit) {
	std::vector< std::vector<int> > new_type(MAP_WBLOCK, std::vector<int>(MAP_HBLOCK));

	for (int x = 0; x < MAP_WBLOCK; ++x) {
		for (int y = 0; y < MAP_HBLOCK; ++y) {
			int cnt = countAliveNeighbours(x, y, type);

			if (type[x][y] == TILE_TYPE_BLOCK) {
				if (cnt < deathLimit) {
					new_type[x][y] = TILE_TYPE_NONE;
				}
				else {
					new_type[x][y] = TILE_TYPE_BLOCK;
				}
			}
			else {
				if (cnt > birthLimit) {
					new_type[x][y] = TILE_TYPE_BLOCK;
				}
				else {
					new_type[x][y] = TILE_TYPE_NONE;
				}
			}
		}
	}
	type = new_type;
}

void GenerateRandomCaveLevel(std::vector< std::vector<int> >& type, std::vector< std::vector<int> >& text){
	const int chanceToStartAlive = 45; // %
	const int simulationSteps = 100;
	const int deathLimit = 3;
	const int birthLimit = 4;

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, 100);

	for (int x = 0; x < MAP_WBLOCK; ++x) {
		for (int y = 0; y < MAP_HBLOCK; ++y) {
			if (dis(gen) <= chanceToStartAlive) {
				type[x][y] = TILE_TYPE_BLOCK;
			}
			else {
				type[x][y] = TILE_TYPE_NONE;
			}
		}
	}

	for (int i = 0; i < simulationSteps; ++i) {
		doSimulationStep(type, deathLimit, birthLimit);
	}

	for (int x = 0; x < MAP_WBLOCK; ++x) {
		for (int y = 0; y < MAP_HBLOCK; ++y) {
			/////////////////////////////////////
			if (y < 8) {
				type[x][y] = TILE_TYPE_NONE;
			}
			if (x == 0 || x == MAP_WBLOCK - 1) {
				type[x][y] = TILE_TYPE_BLOCK;
			}
			/////////////////////////////////////
			if (type[x][y] == TILE_TYPE_BLOCK) {
				text[x][y] = TILE_TEXT_BRICK;
			}
			else {
				text[x][y] = TILE_TEXT_NONE;
			}
		}
	}
}

void App::Generator()
{
	FILE *kek = fopen("Maps/1.map", "w");

	std::vector< std::vector<int> > type(MAP_WBLOCK, std::vector<int>(MAP_HBLOCK));
	std::vector< std::vector<int> > text(MAP_WBLOCK, std::vector<int>(MAP_HBLOCK));
	
	GenerateRandomCaveLevel(type, text);

	for (int i = 0; i < MAP_WBLOCK; ++i) {
		for (int j = 0; j < MAP_HBLOCK; ++j) {
			fprintf(kek, "%d:%d ", text[i][j], type[i][j]);
		}
		fprintf(kek, "\n");
	}
	fclose(kek);
}
