#include "Barbarian.h"

Barbarian::Barbarian(const char* name, size_t health, size_t dexterity, size_t energy, size_t baseAttack) : Hero(
	name, 2 * health, 0.6 * dexterity, 1.5 * energy, 2 * baseAttack, 10, 3)
{
}