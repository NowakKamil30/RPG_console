#pragma once
#include "Moster.h"
class Skeleton :
	public Moster
{
public:
	Skeleton(int level);
	virtual FightData specialAttack();
	virtual ~Skeleton();
};

