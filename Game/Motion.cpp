#include "pch.h"

#include "Motion.h"

bool Motion::MoveTo(float toX, float toY) {
	if (StopMove(toX, toY)) {
		return false;
	}
	return true;
}

bool Motion::StopMove(float toX, float toY) {
	if (toX >= 0 && toX < MAP_WBLOCK && toY >= 0 && toY < MAP_HBLOCK 
		&& App::Game_Map.MAP[toX][toY].TypeID == TILE_TYPE_BLOCK) {
		return true;
	}
	return false;
}

bool Motion::Gravity(float& X, float& Y) {
	if (X < 0 || X >= MAP_WBLOCK || Y < -1 || Y >= MAP_HBLOCK
		|| App::Game_Map.MAP[X][Y+1].TypeID != TILE_TYPE_BLOCK) {
		Y++;
		return true;
	}
	return false;
}