#include "Hero.h"
#include <cstring>
#include <iostream>
#include "Weapon.h"

Hero::Hero()
{
	const char* DEFAULT_NAME = "Hero";
	const int nameLength = strlen(DEFAULT_NAME);
	this->name = new char[nameLength + 1];
	strcpy(this->name, DEFAULT_NAME);

	this->health = 10;
	this->dexterity = 10;
	this->energy = 10;
	this->baseAttack = 5;

	this->experience = 0;
	this->level = 1;

	this->healthOnLevelUp = 5;
	this->dexterityOnLevelUp = 5;

	this->weapon = nullptr;
}

Hero::Hero(const char* name, size_t health, size_t dexterity, size_t energy, size_t baseAttack, size_t healthOnLevelUp,
	size_t dexterityOnLevelUp) : experience(0), level(1)
{
	const int nameLength = strlen(name);
	this->name = new char[nameLength + 1];

	this->health = health;
	this->dexterity = dexterity;
	this->energy = energy;
	this->baseAttack = baseAttack;
	this->healthOnLevelUp = healthOnLevelUp;
	this->dexterityOnLevelUp = dexterityOnLevelUp;
}

Hero::Hero(const Hero& other)
{
	copyFrom(other);
}

Hero& Hero::operator=(const Hero& other)
{
	if (this != &other)
	{
		erase();
		copyFrom(other);
	}

	return *this;
}

void Hero::equip(const Weapon& weapon)
{
	if (weapon.getMinimumDexterity() > this->dexterity)
	{
		throw std::invalid_argument("Could not equip weapon, minimum dexterity requirement not met"); 
	}

	if (this->weapon != nullptr)
	{
		delete this->weapon;
	}
	this->weapon = new Weapon(weapon);
}

Hero::~Hero()
{
	erase();
}

size_t Hero::getEnergy() const
{
	return this->energy;
}

const Weapon* Hero::getWeapon() const
{
	return this->weapon;
}

size_t Hero::getHealth() const
{
	return this->health;
}

size_t Hero::getBaseAttack() const
{
	return this->baseAttack;
}

size_t Hero::getLevel() const
{
	return this->level;
}

size_t Hero::getExperience() const
{
	return this->experience;
}

void Hero::grantExperience(size_t experience)
{
	this->experience += experience;
	size_t oldLevel = this->level;
	this->level = 1 + this->experience / 100;
	this->dexterity += dexterityOnLevelUp * (this->level - oldLevel);
	this->health += healthOnLevelUp * (this->level - oldLevel);
}

void Hero::copyFrom(const Hero& other)
{
	const int nameLength = strlen(other.name) + 1;
	this->name = new char[nameLength];
	strcpy(this->name, other.name);

	this->health = other.health;
	this->dexterity = other.dexterity;
	this->energy = other.energy;
	this->baseAttack = other.baseAttack;

	this->experience = other.experience;
	this->level = other.level;

	this->healthOnLevelUp = other.healthOnLevelUp;
	this->dexterityOnLevelUp = other.dexterityOnLevelUp;

	if (other.weapon != nullptr)
	{
		this->weapon = new Weapon(*other.weapon);
	}
	else
	{
		this->weapon = nullptr;
	}
}

void Hero::erase()
{
	delete[] this->name;
	if (this->weapon != nullptr)
	{
		delete this->weapon;
	}
}