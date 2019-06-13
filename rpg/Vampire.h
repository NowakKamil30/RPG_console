#pragma once
#include "Moster.h"
class Vampire :
	public Moster
{
public:
	Vampire(int level);
	virtual FightData specialAttack();
	virtual ~Vampire();
};

