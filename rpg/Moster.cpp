#include "Moster.h"
#include <iostream>

Moster::Moster(int level)
{
	this->level = level;
}

FightData Moster::attack()
{
	int damag = rand() % (int)(damage * 0.2) + (damage - 0.1 * damage);
	int damageTab[4] = { 0,0,0,damag };
	int healthTab[4] = { 0,0,0,0 };
	FightData fd(damageTab,healthTab);
	std::cout << " zadal: " << damag << " twojemu bohaterowi" << std::endl;
	return fd;
}

bool Moster::dead()
{
	if (currentHp <=0)
	{
		return true;
	}
	return false;
}

Moster::~Moster()
{
}

void Moster::takeDamage(int damage)
{
	currentHp -= damage;
	if (currentHp < 0)
	{
		currentHp = 0;
	}
}

std::string Moster::getName()
{
	return name;
}

int Moster::getHp()
{
	return hp;
}

int Moster::getCurrentHp()
{
	return currentHp;
}
