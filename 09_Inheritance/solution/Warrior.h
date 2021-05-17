#pragma once
#include "Hero.h"

class Warrior : public Hero
{
public:
	Warrior(const char* name, size_t health, size_t dexterity, size_t energy, size_t baseAttack);
};
