#pragma once
#include "Heroes.h"
class Paladin :
	public Heroes
{
public:
	Paladin(DefaultStatistics df);
	virtual FightData attack();
	virtual void levelUp();
	virtual FightData spellMenu();
	virtual ~Paladin() {};
private:
	FightData chooseSpell();
	FightData heal();
	FightData lightAttack();
};

