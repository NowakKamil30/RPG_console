#include "Tief.h"
#include <iostream>
using namespace std;
Tief::Tief(DefaultStatistics df):Heroes(df){}

FightData Tief::attack()
{
	int random = rand() % (int)(statistics.getDamage() * 0.6) + int(statistics.getDamage() * 0.8);
	int tableDamage[4];
	int tablehealth[4];
	for (int i = 0; i < 4; i++)
	{
		tableDamage[i] = 0;
		tablehealth[i] = 0;
	}
	tableDamage[3] = 0;
	int targetIndex = yourChoice();
	tableDamage[targetIndex] = random;

	FightData fd(tableDamage, tablehealth);
	return fd;
}

void Tief::levelUp()
{
	statistics.setLevel(statistics.getLevel() + 1);
	statistics.setDamage(statistics.getDamage() * 1.7);
	statistics.setMagicDamage(statistics.getMagicDamage() + 40);
	statistics.setHp(statistics.getHp() + 40);
	statistics.setCurrentHp(statistics.getCurrentHp() + 40);
	statistics.setMana(statistics.getMana() * 1.3);
	statistics.setCurrentMana(statistics.getCurrentMana() * 1.3);
	statistics.setGold(statistics.getGold() + 20 * statistics.getLevel());
}

FightData Tief::spellMenu()
{
	cout << "--------------------------------------------------------------" << endl << endl;
	cout << "wybierz zaklecie:" << endl;
	cout << "1. zamach(koszt: " << statistics.getLevel() * 20 + 50 << " many. zadaj losowemu celowi 500% obrazen(uwaga martwi wrogie tez moga zostac wybrani jako cel)(" << (int)(statistics.getDamage() * 5)<<")" << endl;
	cout << "2. moderstwo(koszt " << statistics.getLevel() * 23 + 50 << " many. zadaj wybranemu celowi 100% swojeggo damage(" << (int)(statistics.getDamage())<< ")" << endl;
	cout << "3. uzyj zwyklego ataku zadaj wybranemu przeciwnikowi od 80% do 140% swojego ataku("<<(int)(statistics.getDamage()*0.8)<<"-"<< (int)(statistics.getDamage() * 1.4) << endl;
	return chooseSpell();
}

FightData Tief::chooseSpell()
{
	FightData df;
	string spell;
	getline(std::cin >> ws, spell);
	if (spell == "1")
	{
		if (statistics.getCurrentMana() >= statistics.getLevel() * 20 + 100)
		{
			statistics.setCurrentMana(statistics.getCurrentMana() - (statistics.getLevel() * 20 + 100));
			df = assassination();
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
			df = murder();
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

FightData Tief::assassination()
{
	int tableDamage[4];
	int tablehealth[4];
	int random = rand() % 3;
	for (int i = 0; i < 4; i++)
	{
		tableDamage[i] = 0;
		tablehealth[i] = 0;
	}
	tableDamage[random] = statistics.getDamage()*5;
	FightData fd(tableDamage, tablehealth);
	return fd;
}

FightData Tief::murder()
{
	int tableDamage[4];
	int tablehealth[4];
	for (int i = 0; i < 4; i++)
	{
		tableDamage[i] = 0;
		tablehealth[i] = 0;
	}
	int targetIndex = yourChoice();
	tableDamage[targetIndex] = statistics.getDamage();
	FightData fd(tableDamage, tablehealth);
	return fd;
}
