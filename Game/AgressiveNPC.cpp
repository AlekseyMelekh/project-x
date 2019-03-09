#include "pch.h"
#include "AgressiveNPC.h"

AgressiveNPC::AgressiveNPC() : Entity(){
	overlook = 5;
}

void AgressiveNPC::OnLoop() {
	this->Entity::OnLoop();
}