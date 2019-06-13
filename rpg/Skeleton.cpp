#include "Skeleton.h"
#include <iostream>

Skeleton::Skeleton(int level):Moster(level)
{
	hp = 10 * level;
	currentHp = hp;
	damage = 10 * level;
	name = "szkielet";
	magicDamage = 2 * level;
}

FightData Skeleton::specialAttack()
{
	int damage = (this->damage + this->magicDamage) * 1.1;
	int damageTab[4] = { 0,0,0,damage };
	int healthTab[4] = { 0,0,0,0 };
	FightData fd(damageTab, healthTab);
	std::cout << " uzywa specjalnej zdolnosci: " << std::endl;
	std::cout << " zadal: " << damage << " twojemu bohaterowi" << std::endl;
	return fd;
}

Skeleton::~Skeleton()
{
}

