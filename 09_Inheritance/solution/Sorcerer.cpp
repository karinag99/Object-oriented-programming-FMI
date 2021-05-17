#include "Sorcerer.h"

Sorcerer::Sorcerer(const char* name, size_t health, size_t dexterity, size_t energy, size_t baseAttack) : Hero(
	name, 1.2 * health, 2 * dexterity, 2 * energy, 0.5 * baseAttack, 4, 10)
{
}
