#include "pch.h"

#include "Main.h"

void App::Loop()
{
	for (int i = 0; i < Entity::EntityList.size(); i++) {
		if (!Entity::EntityList[i]) continue;

		Entity::EntityList[i]->OnLoop();
	}
	CheckFlags();
	Hero.OnLoop();
}