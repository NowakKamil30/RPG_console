#include "DefaultStatistics.h"
int DefaultStatistics::getLevel()
{
	return level;
}

int DefaultStatistics::getHp()
{
	return hp;
}

int DefaultStatistics::getCurrentHp()
{
	return currentHp;
}

int DefaultStatistics::getMana()
{
	return mana;
}

int DefaultStatistics::getCurrentMana()
{
	return currentMana;
}

int DefaultStatistics::getDamage()
{
	return damage;
}

int DefaultStatistics::getMagicDamage()
{
	return magicDamage;
}

int DefaultStatistics::getGold()
{
	return gold;
}

std::string DefaultStatistics::getClassName()
{
	return className;
}

std::string DefaultStatistics::getHeroName()
{
	return heroName;
}
void DefaultStatistics::setLevel(int level)
{
	this->level = level;
}
void DefaultStatistics::setHp(int hp)
{
	this->hp = hp;
}
void DefaultStatistics::setCurrentHp(int currentHp)
{
	if (currentHp >= hp)
		this->currentHp = hp;
	else if (currentHp > 0)
		this->currentHp = currentHp;
	else
		this->currentHp = 0;
}
void DefaultStatistics::setMana(int mana)
{
	this->mana = mana;
}
void DefaultStatistics::setCurrentMana(int currentMana)
{
	if (currentMana >= mana)
		this->currentMana = mana;
	else if (currentMana > 0)
		this->currentMana = currentMana;
	else
		this->currentMana = 0;
}
void DefaultStatistics::setDamage(int damage)
{
	this->damage = damage;
}
void DefaultStatistics::setMagicDamage(int magicDamage)
{
	this->magicDamage = magicDamage;
}
void DefaultStatistics::setGold(int gold)
{
	this->gold = gold;
}
void DefaultStatistics::setDifficultName(std::string difficult)
{
	this->difficult = difficult;
}
void DefaultStatistics::setClassName(std::string className)
{
	this->className = className;
}
void DefaultStatistics::setHeroName(std::string heroName)
{
	this->heroName = heroName;
}
std::string DefaultStatistics::getDifficultName()
{
	return difficult;
}
double DefaultStatistics::getDifficultValue()
{
	double value=1;
	if (difficult == "easy")
	{
		value = 1.2;
	}
	else if (difficult == "hard")
	{
		value = 0.8;
	}
	return value;
}
DefaultStatistics::DefaultStatistics(int level, int hp,int currentHp, int mana,int currentMana, int damage, int magicDamage, int gold, std::string className, std::string heroName, std::string difficult)
{
	this->level = level;
	this->hp = hp;
	this->currentHp = currentHp;
	this->mana = mana;
	this->currentMana = currentMana;
	this->damage = damage;
	this->magicDamage = magicDamage;
	this->gold = gold;
	this->className = className;
	this->heroName = heroName;
	this->difficult = difficult;
}
