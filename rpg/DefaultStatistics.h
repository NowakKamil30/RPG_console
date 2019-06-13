#pragma once
#include <string>

class DefaultStatistics
{
private:
	int level;
	int hp;
	int currentHp;
	int mana;
	int currentMana;
	int damage;
	int magicDamage;
	int gold;
	std::string className;
	std::string heroName;
	std::string difficult;
public:
	int getLevel();
	int getHp();
	int getCurrentHp();
	int getMana();
	int getCurrentMana();
	int getDamage();
	int getMagicDamage();
	int getGold();
	std::string getDifficultName();
	double getDifficultValue();
	std::string getClassName();
	std::string getHeroName();
	void setLevel(int level);
	void setHp(int hp);
	void setCurrentHp(int currentHp);
	void setMana(int mana);
	void setCurrentMana(int currentMana);
	void setDamage(int damage);
	void setMagicDamage(int magicDamage);
	void setGold(int gold);
	void setDifficultName(std::string difficult);
	void setClassName(std::string className);
	void setHeroName(std::string heroName);
	DefaultStatistics(
		int level = 1,
		int hp = 100,
		int currentHp = 100,
		int mana = 100,
		int currentMana = 100,
		int damage = 10,
		int magicDamage = 10,
		int gold = 100,
		std::string className = "Mage",
		std::string heroName = "undefined",
		std::string difficult = "normal"
	);
};

