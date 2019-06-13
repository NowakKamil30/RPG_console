#pragma once
#include "Heroes.h"
#include "DefaultStatistics.h"
class Mage :
	public Heroes
{
public:
	Mage(DefaultStatistics df);
	virtual FightData attack();
	virtual void levelUp();
	virtual FightData spellMenu();
	virtual ~Mage() {};
private:
	FightData chooseSpell();
	FightData fireBall();
	FightData lightning();
};

