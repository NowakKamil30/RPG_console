#include "Warrior.h"
#include <iostream>
using namespace std;
Warrior::Warrior(DefaultStatistics df):Heroes(df){}

FightData Warrior::attack()
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
	statistics.setDamage(statistics.getDamage()+1);
	FightData fd(tableDamage, tablehealth);
	return fd;
}

void Warrior::levelUp()
{
	statistics.setLevel(statistics.getLevel() + 1);
	statistics.setDamage(statistics.getDamage() * 1.6);
	statistics.setMagicDamage(statistics.getMagicDamage() + 10);
	statistics.setHp(statistics.getHp() + 90);
	statistics.setCurrentHp(statistics.getCurrentHp() + 90);
	statistics.setMana(statistics.getMana() * 1.1+10);
	statistics.setCurrentMana(statistics.getCurrentMana() * 1.1+10);
	statistics.setGold(statistics.getGold() + 20 * statistics.getLevel());
}

FightData Warrior::spellMenu()
{
	cout << "--------------------------------------------------------------" << endl << endl;
	cout << "wybierz zaklecie:" << endl;
	cout << "1. silne uderzenie(koszt: " << statistics.getLevel() * 5+40 << " many. zadaj 150% normalnych obrazen(" << (int)(statistics.getDamage() * 1.5) << ") twojejego ataku)" << endl;
	cout << "2. furia(koszt " << statistics.getLevel() * 10 + 60 << " many. Dodaje 10% sily magidznej do twojego twojej statytyki atak(" << (int)(statistics.getMagicDamage()*0.09) << ") twojej sily magicznej)" << endl;
	cout << "3. uzyj zwyklego ataku " << statistics.getDamage() << " dla glownego celu i dodaj jeden punkt ataku do statystyk" << endl;
	return chooseSpell();
}

FightData Warrior::chooseSpell()
{
	FightData df;
	string spell;
	getline(std::cin >> ws, spell);
	if (spell == "1")
	{
		if (statistics.getCurrentMana() >= statistics.getLevel() * 5 + 40)
		{
			statistics.setCurrentMana(statistics.getCurrentMana() - (statistics.getLevel() * 5 + 40));
			df = powerfulBlow();
		}
		else
		{
			cout << "masz za malo many" << endl;
			df = spellMenu();
		}

	}
	else if (spell == "2")
	{
		if (statistics.getCurrentMana() >= statistics.getLevel() * 10 + 60)
		{
			statistics.setCurrentMana(statistics.getCurrentMana() - (statistics.getLevel() * 10 + 60));
			df = Furia();
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

FightData Warrior::Furia()
{
	int tableDamage[4];
	int tablehealth[4];
	for (int i = 0; i < 4; i++)
	{
		tableDamage[i] = 0;
		tablehealth[i] = 0;
	}
	tableDamage[3] = 0;
	statistics.setDamage(statistics.getDamage()+statistics.getMagicDamage()*0.1);
	FightData fd(tableDamage, tablehealth);
	return fd;
}

FightData Warrior::powerfulBlow()
{
	int tableDamage[4];
	int tablehealth[4];
	for (int i = 0; i < 4; i++)
	{
		tableDamage[i] = 0;
		tablehealth[i] = 0;
	}
	int targetIndex = yourChoice();
	tableDamage[targetIndex] = statistics.getMagicDamage() * 1.5;

	FightData fd(tableDamage, tablehealth);
	return fd;
}


