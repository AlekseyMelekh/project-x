#pragma once

#include <SDL.h>

#include "Entity.h"

class MainHero : public Entity{
public:
	MainHero();
	void OnLoop();
};