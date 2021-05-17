#pragma once
#include "Hero.h"


class Assassin : public Hero
{
public:
	Assassin(const char* name, size_t health, size_t dexterity, size_t energy, size_t baseAttack);
};
