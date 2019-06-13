#pragma once
#include "Moster.h"

class Spider :
	public Moster
{
public:
	Spider(int level);
	virtual FightData specialAttack();
	virtual ~Spider();
};

