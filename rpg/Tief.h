#pragma once
#include "Heroes.h"
class Tief :
	public Heroes
{
public:
	Tief(DefaultStatistics df);
	virtual FightData attack();
	virtual void levelUp();
	virtual FightData spellMenu();
	virtual ~Tief() {};
private:
	FightData chooseSpell();
	FightData assassination();
	FightData murder();
};

