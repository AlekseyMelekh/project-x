#pragma once

#include "Entity.h"

enum AgroType {
	ZOMBIE
};

enum action {
	CHILL,
	GO_TO_THE_RIGHT,
	GO_TO_THE_LEFT,
	COUNT,
	NONE
};

class AgressiveNPC : public Entity{
private:
	AgroType type;
	int overlook;
	action act;
	int time_of_act;
	int time_of_start;
	bool check_after_jump;
	float prev_X, prev_Y;
public:
	AgressiveNPC();
	void OnLoop();
	void OnRender(SDL_Renderer* renderer, float, float, std::vector<AgressiveNPC>&);
	virtual action Trigger();
	virtual action GenerateAction();
};
