#include "Weapon.h"

#include <cstring>
Weapon::Weapon()
{
	const char* DEFAULT_NAME = "No name";
	const int defaultNameLength = strlen(DEFAULT_NAME);
	this->name = new char[defaultNameLength + 1];

	this->attack = 5;
	this->minimumDexterity = 1;
	this->energyCost = 2;
}

Weapon::Weapon(const char* name, size_t attack, size_t minimumDexterity, size_t energyCost)
{
	const int nameLength = strlen(name);
	this->name = new char[nameLength + 1];

	this->attack = attack;
	this->minimumDexterity = minimumDexterity;
	this->energyCost = energyCost;
}

size_t Weapon::getEnergyCost() const
{
	return this->energyCost;
}

Weapon::Weapon(const Weapon& other)
{
	copyFrom(other);
}

Weapon& Weapon::operator=(const Weapon& other)
{
	if (this != &other)
	{
		erase();
		copyFrom(other);
	}

	return *this;
}

Weapon::~Weapon()
{
	erase();
}

size_t Weapon::getMinimumDexterity() const
{
	return this->minimumDexterity;
}

size_t Weapon::getAttack() const
{
	return this->attack;
}

void Weapon::copyFrom(const Weapon& other)
{
	const int nameLength = strlen(other.name);

	this->name = new char[nameLength + 1];
	strcpy(this->name, other.name);

	this->attack = other.attack;
	this->minimumDexterity = other.minimumDexterity;
	this->energyCost = other.energyCost;
}

void Weapon::erase()
{
	delete[] name;
}