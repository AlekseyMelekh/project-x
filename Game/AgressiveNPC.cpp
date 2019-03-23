#include "pch.h"
#include "AgressiveNPC.h"
#include <time.h>
#include "Define.h"
#include "Motion.h"

AgressiveNPC::AgressiveNPC() : Entity(){
	overlook = 20;
	time_of_start = time_of_act = 0;
	check_after_jump = false;
}

void AgressiveNPC::OnLoop() {
	this->Entity::OnLoop();
	action tmp = Trigger();
	if(tmp != NONE){
		act = tmp;
	}
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

void AgressiveNPC::OnRender(SDL_Renderer* renderer, float MapX, float MapY, std::vector<AgressiveNPC>& v) {
	float height = WHEIGHT / TILE_SIZE, weight = WWIDTH / TILE_SIZE;
	for (int i = 0; i < NUM_AGR_NPC; ++i) {
		int curX = X;
		int curY = Y;
		float X1 = (curX - MapX) * TILE_SIZE;
		float Y1 = (curY - MapY) * TILE_SIZE;
		if ((v[i].X >= MapX - 2 || v[i].X <= weight + 2)
		&& (v[i].Y >= MapY - 2 || v[i].Y <= height + 2)) {
			DrawTexture(Texture_Entity, renderer, X1, Y1, AnimState * Width, Anim_Control.GetCurrentFrame() * Height + Height * Anim_Control.MaxFrames * side, Width, Height);
		}
	}
}

action AgressiveNPC::Trigger() {
	for (int i = -overlook; i <= overlook; ++i) {
		for (int j = -overlook; j <= overlook; ++j) {
			int checkX = i + X, checkY = j + Y;
			if ((int)App::Hero.X == checkX && (int)App::Hero.Y == checkY) {
				time_of_act = 1.0;
				time_of_start = SDL_GetTicks();
				if ((int)App::Hero.X == (int)X) {
					return CHILL;
				}
				if ((int)App::Hero.X < (int)X) {
					return GO_TO_THE_LEFT;
				}
				else {
					return GO_TO_THE_RIGHT;
				}
			}
		}
	}
	return NONE;
}