#pragma once

#include <vector>
#include <string>

#include "Animation.h"
#include "Texture.h"

enum type {
	PLAYER,
	ANGRY_NPC,
	KIND_NPC
};

class Entity {
public:
	static std::vector<Entity*>    EntityList;

protected:
	Animation		Anim_Control;

	SDL_Texture*    Texture_Entity;

public:
	float           X;
	float           Y;

	int             Width;
	int             Height;

	int             AnimState;
	int				TypeEntity;

	float			FLYING;
	bool			STAY;

public:
	Entity();

	virtual ~Entity();

public:
	virtual bool OnLoad(std::string File, SDL_Renderer* renderer, int Width, int Height, int MaxFrames);

	virtual void OnLoop();

	virtual void OnRender(SDL_Renderer* renderer);

	virtual void OnCleanup();
};