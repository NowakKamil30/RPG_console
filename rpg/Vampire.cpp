#include "Vampire.h"
#include <iostream>
Vampire::Vampire(int level):Moster(level)
{
	damage = level * 20;
	magicDamage = level * 20;
	hp = level * 20;
	name = "wampir";
	currentHp = hp;
}

FightData Vampire::specialAttack()
{
	int damage = this->damage + this->magicDamage;
	int damageTab[4] = { 0,0,0,damage };
	int healthTab[4] = { damage/2,0,0,0 };
	FightData fd(damageTab, healthTab);
	std::cout << " uzywa specjalnej zdolnosci: " << std::endl;
	std::cout << "zadal " << damage << " uleczyl sie o " << damage / 2 << "punktow zycia" << std::endl;
	return fd;
}

Vampire::~Vampire()
{
}
