#include "Spider.h"
#include <iostream>

Spider::Spider(int level):Moster(level)
{
	hp = 20 * level;
	damage = 5 * level;
	magicDamage = 6 * level;
	currentHp = hp;
	name = "pajak";
}

FightData Spider::specialAttack()
{
	int damageTab[4] = { 0,0,0,0 };
	int healthTab[4] = { magicDamage,0,0,0 };
	FightData fd(damageTab, healthTab);
	std::cout<<" uzywa specjalnej zdolnosci: "<<std::endl;
	std::cout << "uleczyl sie o " << magicDamage << " punktow zycia" << std::endl;
	return fd;
}

Spider::~Spider()
{
}

