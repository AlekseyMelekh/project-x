#include "pch.h"

#include "Entity.h"
#include "Motion.h"
#include "Define.h"
#include <string>

std::vector<Entity*> Entity::EntityList;

Entity::Entity() {
	Texture_Entity = NULL;

	TypeEntity = KIND_NPC;

	X = Y = 0.0f;
	CAN_JUMP = true;

	Width = Height = 0;
	STAY = true;
	FLYING = speedr = speedf = 0;

	AnimState = 0;
}

Entity::~Entity() {
}

bool Entity::OnLoad(std::string File, SDL_Renderer* renderer, int Width, int Height, int MaxFrames) {
	if ((Texture_Entity = LoadImage(File, renderer)) == NULL) {
		return false;
	}

	//Texture::Transparent(Texture_Entity, 255, 0, 255);

	this->Width = Width;
	this->Height = Height;

	Anim_Control.MaxFrames = MaxFrames;

	return true;
}

void Entity::OnLoop() {
	if (Motion::MoveTo(X + speedr, Y)) {
		X += speedr;
	}
	else {
		//speedr = 0;
	}
	X = round(X * 10) / 10;
	Y = round(Y * 10) / 10;
	if (FLYING < EPS) {
		if (!Motion::Gravity(speedf, X, Y)) {
			Y = round(Y);
			STAY = true;
			speedf = 0;
			Anim_Control.OnAnimate();
		}
		else {
			STAY = false;
		}
	}
	else {
		Motion::Jump(FLYING, STAY, X, Y);
	}
}

void Entity::OnRender(SDL_Renderer* renderer) {
	if (Texture_Entity == NULL || renderer == NULL) return;

	DrawTexture(Texture_Entity, renderer, WWIDTH / 2, WHEIGHT / 2, AnimState * Width, Anim_Control.GetCurrentFrame() * Height, Width, Height);
}

void Entity::OnCleanup() {
	if (Texture_Entity) {
		SDL_DestroyTexture(Texture_Entity);
	}

	Texture_Entity = NULL;
}