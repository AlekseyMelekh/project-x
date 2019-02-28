#include "pch.h"

#include "Motion.h"

bool Motion::MoveTo(float toX, float toY) {
	if (StopMove(toX, toY)) {
		return false;
	}
	return true;
}

bool Motion::StopMove(float toX, float toY) {
	if ((int)toX >= 0 && toX < MAP_WBLOCK && (int)toY >= 0 && toY < MAP_HBLOCK 
		&& App::Game_Map.MAP[toX][toY].TypeID == TILE_TYPE_BLOCK) {
		return true;
	}
	return false;
}

bool Motion::Gravity(float& X, float& Y) {
	std::cout << std::fixed << std::setprecision(5) <<  "X= " << X << " Y= " << Y << ' ' << (int)Y + 2 << ' ' << abs(ceil(X)) << ' ' << (int)X << '\n';
	if (ceil(X) < 0 || X > MAP_WBLOCK || Y < -2 || Y > MAP_HBLOCK
		|| fabs(X - MAP_WBLOCK) < EPS || fabs(Y - MAP_HBLOCK) < EPS
		|| (App::Game_Map.MAP[abs((int)X)][(int)(abs(Y))+2].TypeID != TILE_TYPE_BLOCK
		&& App::Game_Map.MAP[abs(ceil(X))][(int)Y+2].TypeID != TILE_TYPE_BLOCK)) {
		Y++;
		return true;
	}
	return false;
}