#pragma once
#include <string>
#include "FightData.h"
class Moster
{
protected:
	int hp;
	int currentHp;
	int damage;
	int magicDamage;
	int level;
	std::string name;
public:
	Moster(int level);
	FightData attack();
	virtual FightData specialAttack() = 0;
	bool dead();
	virtual ~Moster();
	void takeDamage(int damage);
	std::string getName();
	int getHp();
	int getCurrentHp();
	/*
	void setHp(int hp);
	void setCurrentHp(int currentHp);
	void setDamage(int damage);
	void setMagicDamage(int magicDamage);
	int getHp();
	int getCurrentHp();
	int getDamage();
	*/

};

