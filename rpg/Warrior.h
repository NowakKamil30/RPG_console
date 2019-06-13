#pragma once
#include "Heroes.h"
class Warrior :
	public Heroes
{
public:
	Warrior(DefaultStatistics df);
	virtual FightData attack();
	virtual void levelUp();
	virtual FightData spellMenu();
	virtual ~Warrior() {};
private:
	FightData chooseSpell();
	FightData Furia();
	FightData powerfulBlow();
};

