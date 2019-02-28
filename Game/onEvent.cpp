#include "pch.h"

#include "Main.h"

void App::onEvent(SDL_Event* Event)
{
	Events::OnEvent(Event);
}

void App::OnExit() {
	Running = false;
}

void App::OnKeyDown(SDL_Keycode sym, int mod, int unicode){
	switch (sym) {
	//case SDLK_UP:    if (Motion::MoveTo(Hero.X, Hero.Y - 1)) Hero.Y -= STEP; break;
	//case SDLK_DOWN:  if (Motion::MoveTo(Hero.X, Hero.Y + 1)) Hero.Y += STEP; break;
	case SDLK_a:  if (Motion::MoveTo(Hero.X - STEP, Hero.Y)) Hero.X -= STEP; break;
	case SDLK_d: if (Motion::MoveTo(Hero.X + STEP, Hero.Y)) Hero.X += STEP; break;
	case SDLK_SPACE: if(Hero.STAY) Hero.FLYING = 4; break;

	default: {
	}
	}
}