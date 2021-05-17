#pragma once
#include "Hero.h"

class Barbarian : public Hero
{
public:
	Barbarian(const char* name, size_t health, size_t dexterity, size_t energy, size_t baseAttack);
};
