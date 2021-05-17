#pragma once
#include "Hero.h"

class Sorcerer : public Hero
{
public:
	Sorcerer(const char* name, size_t health, size_t dexterity, size_t energy, size_t baseAttack);
};
