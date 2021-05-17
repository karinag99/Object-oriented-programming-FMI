#include "Assassin.h"

Assassin::Assassin(const char* name, size_t health, size_t dexterity, size_t energy, size_t baseAttack) : Hero(
	name, 0.7 * health, 2 * dexterity, 1.3 * energy, 2 * baseAttack, 5, 10)
{
}
