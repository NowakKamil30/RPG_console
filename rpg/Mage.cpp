#include "Mage.h"
#include <iostream>
#include <sstream>
using namespace std;
void Mage::levelUp()
{
	statistics.setLevel(statistics.getLevel() + 1);
	statistics.setDamage(statistics.getDamage() * 1.2);
	statistics.setMagicDamage(statistics.getMagicDamage() +60);
	statistics.setHp(statistics.getHp() + 60);
	statistics.setCurrentHp(statistics.getCurrentHp() + 60);
	statistics.setMana(statistics.getMana() * 1.2);
	statistics.setCurrentMana(statistics.getCurrentMana() * 1.2);
	statistics.setGold(statistics.getGold() + 20 * statistics.getLevel());
}

FightData Mage::spellMenu()
{
	cout << "--------------------------------------------------------------" << endl << endl;
	cout << "wybierz zaklecie:" << endl;
	cout << "1. kula ognia(koszt: "<<statistics.getLevel()*20+100 <<" many. Zadaj wszystkim przeciwnikam 80%("<<(int)(statistics.getMagicDamage()*0.8) <<") twojej sily magicznej)" << endl;
	cout <<"2. blyskawicza(koszt " << statistics.getLevel() * 23 + 100 << " many. Zadaj wybranemu przeciwnikowi od50% do 150%(" << (int)(statistics.getMagicDamage() * 0.5)<<"-"<< (int)(statistics.getMagicDamage() * 1.5) << ") twojej sily magicznej)" << endl;
	cout << "3. uzyj zwyklego ataku " << statistics.getDamage() << " dla glownego celu i " << (int)(statistics.getDamage() / 5) << " dla pozostalych" << endl;
	return chooseSpell();
}



FightData Mage::chooseSpell()
{
	FightData df;
	string spell;
	getline(std::cin >> ws, spell);
	if (spell == "1")
	{
		if (statistics.getCurrentMana() >= statistics.getLevel() * 20 + 100)
		{
			statistics.setCurrentMana(statistics.getCurrentMana() - (statistics.getLevel() * 20 + 100));
			df = fireBall();
		}
		else
		{
			cout << "masz za malo many" << endl;
			df = spellMenu();
		}
		
	}
	else if (spell == "2")
	{
		if (statistics.getCurrentMana() >= statistics.getLevel() * 20 + 100)
		{
			statistics.setCurrentMana(statistics.getCurrentMana() - (statistics.getLevel() * 20 + 100));
			df = lightning();
		}
		else
		{
			system("cls");
			cout << "masz za malo many" << endl;
			df = spellMenu();
		}
	}
	else if (spell == "3")
	{
		df=attack();
	}
	else
	{
		cout << "nie mozna wykonac takiej akcji prosze wybrac jeszcze raz: ";
		df = chooseSpell();
	}

	return df;
}

FightData Mage::fireBall()
{
	int tableDamage[4];
	int tablehealth[4];
	for (int i = 0; i < 4; i++)
	{
		tableDamage[i] = statistics.getMagicDamage()*0.8;
		tablehealth[i] = 0;
	}
	tableDamage[3] = 0;
	FightData fd(tableDamage, tablehealth);
	return fd;
}

FightData Mage::lightning()
{
	float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	r += 0.5;
	int tableDamage[4];
	int tablehealth[4];
	for (int i = 0; i < 4; i++)
	{
		tableDamage[i] = 0;
		tablehealth[i] = 0;
	}
	int targetIndex = yourChoice();
	tableDamage[targetIndex] = statistics.getMagicDamage()*r;

	FightData fd(tableDamage, tablehealth);
	return fd;
}

Mage::Mage(DefaultStatistics df):Heroes(df){}

FightData Mage::attack()
{

	int tableDamage[4];
	int tablehealth[4];
	for (int i = 0; i < 4; i++)
	{
		tableDamage[i] = statistics.getDamage() / 5;
		tablehealth[i] = 0;
	}
	tableDamage[3] = 0;
	int targetIndex = yourChoice();
	tableDamage[targetIndex] = statistics.getDamage();
	
	FightData fd(tableDamage,tablehealth);
	return fd;
}
