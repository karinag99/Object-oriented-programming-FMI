#include "Enemy.h"

Enemy::Enemy(size_t health, size_t attack, size_t experienceDrop)
{
	this->health = health;
	this->attack = attack;
	this->experienceDrop = experienceDrop;
}

size_t Enemy::getAttack() const
{
	return this->attack;
}

size_t Enemy::getHealth() const
{
	return this->health;
}

size_t Enemy::getExperienceDrop() const
{
	return this->experienceDrop;
}