#include "pch.h"
#include "AgressiveNPC.h"
#include <time.h>
#include "Define.h"
#include "Motion.h"

AgressiveNPC::AgressiveNPC() : Entity(){
	overlook = 10;
	time_of_start = time_of_act = 0;
	check_after_jump = false;
}

void AgressiveNPC::OnLoop() {
	this->Entity::OnLoop();
	if (SDL_GetTicks() - time_of_start > time_of_act) {
		act = GenerateAction();
		switch (act) {
		case CHILL: time_of_start = SDL_GetTicks(), time_of_act = rand() % (second * 4) + 4 * second; break;
		case GO_TO_THE_LEFT: time_of_start = SDL_GetTicks(), time_of_act = rand() % (second * 5) + 5 * second; break;
		case GO_TO_THE_RIGHT: time_of_start = SDL_GetTicks(), time_of_act = rand() % (second * 5) + 5 * second; break;

		default: {
		}
		}
	}

	switch (act) {
		case CHILL: speedr = 0; break;
		case GO_TO_THE_LEFT: speedr = -STEP / 3; break;
		case GO_TO_THE_RIGHT: speedr = STEP / 3; break;

		default: {

		}
	}

	if (Motion::MoveTo(X + speedr, Y)) {
		X += speedr;
	}
	else {
		if (FLYING < EPS && STAY == true) {
			STAY = false;
			FLYING = 4;
			check_after_jump = true;
			prev_X = X, prev_Y = Y;
		}
		//speedr = 0;
	}
	if (speedr != 0) {
		(speedr > 0 ? side = 0 : side = 1);
	}
	X = round(X * 10) / 10;
	Y = round(Y * 10) / 10;
	if (FLYING < EPS) {
		if (!Motion::Gravity(speedf, X, Y)) {
			Y = round(Y);
			if (App::Game_Map.MAP[X][Y + 1].TypeID == TILE_TYPE_BLOCK) {
				X = round(X);
			}
			if (check_after_jump) {
				if (fabs(prev_X - X) < EPS && fabs(prev_Y - Y) < EPS) {
					time_of_act = 0;
				}
				check_after_jump = false;
			}
			STAY = true;
			speedf = 0;
			if (fabs(speedr) > EPS) {
				Anim_Control.OnAnimate();
			}
		}
		else {
			STAY = false;
		}
	}
	else {
		Motion::Jump(FLYING, STAY, X, Y);
	}
}

action AgressiveNPC::GenerateAction() {
	srand(time(nullptr));
	return (action)(rand() % action::COUNT);
}