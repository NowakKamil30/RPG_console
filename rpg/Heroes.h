#pragma once
#include "DefaultStatistics.h"
#include "Hero.h"
class Heroes :
	public Hero
{
public:
	static Heroes* createHero(DefaultStatistics df);
	Heroes(DefaultStatistics df);
	virtual FightData attack()=0;
	//virtual void updateStatistics();
	virtual void levelUp()=0;
	virtual ~Heroes() {};
	void showStatistics();
	virtual FightData spellMenu() = 0;
	DefaultStatistics statistics;
	void takeDamage(int damage);
	bool dead();
protected:
	int yourChoice();

};

