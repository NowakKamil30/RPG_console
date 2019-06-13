#pragma once
#include "FightData.h"
class Hero
{
public:
	virtual FightData attack() = 0;
	//virtual void updateStatistics() = 0;
	virtual void levelUp() = 0;
	virtual FightData spellMenu()=0;
	virtual ~Hero() {};
};

