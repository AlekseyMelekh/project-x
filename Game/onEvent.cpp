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
	case SDLK_UP:    Camera::CameraControl.OnMove(0, -4); break;
	case SDLK_DOWN:  Camera::CameraControl.OnMove(0, 4); break;
	case SDLK_LEFT:  Camera::CameraControl.OnMove(-4, 0); break;
	case SDLK_RIGHT: Camera::CameraControl.OnMove(4, 0); break;

	default: {
	}
	}
}