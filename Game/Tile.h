#pragma once

#include "Define.h"

enum Tile_type{
	TILE_TYPE_NONE,
	TILE_TYPE_NORMAL,
	TILE_TYPE_BLOCK
};

class Tile {
public:
	int     TextureID;
	int     TypeID;

public:
	Tile();
};