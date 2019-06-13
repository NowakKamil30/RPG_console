#include "Paladin.h"
#include <iostream>
using namespace std;
Paladin::Paladin(DefaultStatistics df):Heroes(df){}

FightData Paladin::attack()
{
	int tableDamage[4];
	int tablehealth[4];
	for (int i = 0; i < 4; i++)
	{
		tableDamage[i] = 0;
		tablehealth[i] = 0;
	}
	tableDamage[3] = 0;
	int targetIndex = yourChoice();
	tableDamage[targetIndex] = statistics.getDamage();
	statistics.setCurrentHp(statistics.getCurrentHp() + statistics.getMagicDamage() * 0.1);

	FightData fd(tableDamage, tablehealth);
	return fd;
}

void Paladin::levelUp()
{
	statistics.setLevel(statistics.getLevel() + 1);
	statistics.setDamage(statistics.getDamage() * 1.1);
	statistics.setMagicDamage(statistics.getMagicDamage() + 40);
	statistics.setHp(statistics.getHp() + 110);
	statistics.setCurrentHp(statistics.getCurrentHp() + 110);
	statistics.setMana(statistics.getMana() * 1.1+15);
	statistics.setCurrentMana(statistics.getCurrentMana() * 1.1+15);
	statistics.setGold(statistics.getGold() + 20 * statistics.getLevel());
}

FightData Paladin::spellMenu()
{
	cout << "--------------------------------------------------------------" << endl << endl;
	cout << "wybierz zaklecie:" << endl;
	cout << "1. leczenie(koszt: " << statistics.getLevel() * 10 + 50 << " many. leczysz 30% swoich punktow zdrowia (" << (int)(statistics.getHp() * 0.3)<<")" << endl;
	cout << "2. atak swiatla(koszt " << statistics.getLevel() * 10+50<< " many. zadaj wszyskim swoim wrogom 50% ataku + 50% magicznego ataku" << (int)(statistics.getMagicDamage() * 0.5+statistics.getDamage()*0.5) << ") twojej sily magicznej)" << endl;
	cout << "3. uzyj zwyklego ataku " << statistics.getDamage() << "i leczy cie o 10% twojego magicznego ataku ("<<(int)(statistics.getMagicDamage()*0.1) <<")"<< endl;
	return chooseSpell();
}

FightData Paladin::chooseSpell()
{
	FightData df;
	string spell;
	getline(std::cin >> ws, spell);
	if (spell == "1")
	{
		if (statistics.getCurrentMana() >= statistics.getLevel() * 20 + 100)
		{
			statistics.setCurrentMana(statistics.getCurrentMana() - (statistics.getLevel() * 20 + 100));
			df = heal();
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
			df = lightAttack();
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
		df = attack();
	}
	else
	{
		cout << "nie mozna wykonac takiej akcji prosze wybrac jeszcze raz: ";
		df = chooseSpell();
	}

	return df;
}

FightData Paladin::heal()
{
	int tableDamage[4];
	int tablehealth[4];
	for (int i = 0; i < 4; i++)
	{
		tableDamage[i] = 0;
		tablehealth[i] = 0;
	}
	tablehealth[3] = statistics.getHp() * 0.3;
	FightData fd(tableDamage, tablehealth);
	return fd;
}

FightData Paladin::lightAttack()
{
	int tableDamage[4];
	int tablehealth[4];
	for (int i = 0; i < 4; i++)
	{
		tableDamage[i] = statistics.getMagicDamage() *0.5 +statistics.getDamage()*0.5;
		tablehealth[i] = 0;
	}
	tableDamage[3] = 0;
	FightData fd(tableDamage, tablehealth);
	return fd;
}
