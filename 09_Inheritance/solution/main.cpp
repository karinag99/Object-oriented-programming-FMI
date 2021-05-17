#include <iostream>


#include "Hero.h"
#include "Enemy.h"
#include "Weapon.h"
#include "Barbarian.h"

bool battle(Hero& hero, const Enemy& enemy)
{
	size_t heroEnergy = hero.getEnergy();
	size_t heroHealth = hero.getHealth();
	size_t heroAttack = hero.getBaseAttack();
	const Weapon * heroWeapon = hero.getWeapon();

	size_t enemyHealth = enemy.getHealth();
	size_t enemyAttack = enemy.getAttack();

	while (heroHealth > 0 && enemyHealth > 0)
	{
		size_t attackEnemy = heroAttack;
		if(heroWeapon != nullptr && heroWeapon->getEnergyCost() <= heroEnergy)
		{
			attackEnemy += heroWeapon->getAttack();
			heroEnergy -= heroWeapon->getEnergyCost();
		}
		
		if (attackEnemy > enemyHealth)
		{
			enemyHealth = 0;
		} else
		{
			enemyHealth -= attackEnemy;
		}

		if (enemyHealth == 0)
		{
			break;
		}
		if (enemyAttack > heroHealth)
		{
			heroHealth = 0;
		} else
		{
			heroHealth -= enemyAttack;
		}
	}

	if (enemyHealth == 0)
	{
		hero.grantExperience(enemy.getExperienceDrop());
	}

	return heroHealth > 0;
}

int main()
{
	Barbarian barbarian("Default", 9,9,9,9);
	Enemy enemy;// (100, 10, 10);
	std::cout << "Stats" << std::endl;
	std::cout << "Health: " << barbarian.getHealth() << std::endl;
	std::cout << "Energy: "<< barbarian.getEnergy()<< std::endl;
	std::cout << "BaseAttack: " << barbarian.getBaseAttack()<< std::endl;
	std::cout << "HasWeapon: " << (barbarian.getWeapon() != nullptr) << std::endl;
	std::cout << "Battle vs default enemy: " << battle(barbarian, enemy) << std::endl;
	std::cout << "Battle vs default enemy: " << battle(barbarian, enemy) << std::endl;
	std::cout << "Battle vs default enemy: " << battle(barbarian, enemy) << std::endl;
	std::cout << "Battle vs default enemy: " << battle(barbarian, enemy) << std::endl;
	std::cout << "Level after fighting: " << barbarian.getLevel() << std::endl;
	std::cout << "Experience: " << barbarian.getExperience() << std::endl;
	Enemy strongEnemy(100, 10, 10);
	std::cout << "Battle vs strong enemy: " << battle(barbarian, strongEnemy) << std::endl;
	Weapon weapon("Axe", 100, 9, 10);
	std::cout << "Equipping a strong weapon: " <<  std::endl;
	barbarian.equip(weapon);
	std::cout << "Battle vs strong enemy: " << battle(barbarian, strongEnemy) << std::endl;
	weapon = Weapon("Axe", 100, 8, 3);
	barbarian.equip(weapon);

	std::cout << "Battle vs strong enemy with strong weapon: " << battle(barbarian, strongEnemy) << std::endl;

	return 0;
}
