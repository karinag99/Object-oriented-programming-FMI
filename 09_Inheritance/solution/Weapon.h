#pragma once

class Weapon
{
public:

	Weapon();
	Weapon(const char* name, size_t attack, size_t minimumDexterity, size_t energyCost);
	size_t getEnergyCost() const;
	Weapon(const Weapon& other);
	Weapon& operator=(const Weapon& other);
	~Weapon();
	size_t getMinimumDexterity() const;
	size_t getAttack() const;
	void copyFrom(const Weapon& other);
	void erase();
private:
	char * name;
	size_t minimumDexterity;
	size_t attack;
	size_t energyCost;
};
