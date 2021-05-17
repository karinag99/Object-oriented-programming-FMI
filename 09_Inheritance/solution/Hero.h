#pragma once
#include "Weapon.h"


class Hero
{
public:
	Hero();

	Hero(const char* name, size_t health, size_t dexterity, size_t energy, size_t baseAttack, size_t healthOnLevelUp,
		size_t dexterityOnLevelUp);

	Hero(const Hero& other);

	Hero& operator=(const Hero& other);
	void equip(const Weapon& weapon);


	~Hero();

	size_t getEnergy() const;

	const Weapon* getWeapon() const;

	size_t getHealth() const;

	size_t getBaseAttack() const;
	 
	size_t getLevel() const;
	size_t getExperience() const;

	void grantExperience(size_t experience);

private:
	void copyFrom(const Hero& other);

	void erase();

	char * name;
	size_t health;
	size_t dexterity;
	size_t energy;
	size_t baseAttack;

	size_t experience;
	size_t level;

	size_t healthOnLevelUp;
	size_t dexterityOnLevelUp;

	Weapon * weapon;
};
