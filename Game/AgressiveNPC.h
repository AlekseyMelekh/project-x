#pragma once

#include "Entity.h"

enum AgroType {
	ZOMBIE
};

class AgressiveNPC : public Entity{
private:
	AgroType type;
	int overlook;
public:
	AgressiveNPC();
	void OnLoop();
};
