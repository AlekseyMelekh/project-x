#include "pch.h"

#include "Main.h"

void App::Loop()
{
	//testNPC.OnLoop();
	CheckFlags();
	Hero.OnLoop();
}