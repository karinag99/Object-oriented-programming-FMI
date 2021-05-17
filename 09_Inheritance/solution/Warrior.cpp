#include "Warrior.h"

Warrior::Warrior(const char* name, size_t health, size_t dexterity, size_t energy, size_t baseAttack) : Hero(
	name, 1.5 * health, 1.4 * dexterity, 1.5 * energy, 1.3 * baseAttack, 6, 6)
{
}