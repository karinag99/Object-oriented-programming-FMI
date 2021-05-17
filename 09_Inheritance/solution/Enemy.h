#pragma once

class Enemy
{
public:
	Enemy(size_t health = 10, size_t attack = 5, size_t experienceDrop = 30);

	size_t getAttack() const;

	size_t getHealth() const;

	size_t getExperienceDrop() const;

private:
	size_t health;
	size_t attack;
	size_t experienceDrop;
};