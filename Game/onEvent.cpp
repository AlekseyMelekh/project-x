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
	case SDLK_LEFT:  if (Motion::MoveTo(Hero.X - 1, Hero.Y)) Hero.X -= STEP; break;
	case SDLK_RIGHT: if (Motion::MoveTo(Hero.X + 1, Hero.Y)) Hero.X += STEP; break;

	default: {
	}
	}
}