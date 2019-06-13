#include "Heroes.h"
#include "Mage.h"
#include <iostream>
#include <time.h>
#include <sstream>
#include "Warrior.h"
#include "Paladin.h"
#include "Tief.h"
using namespace std;
Heroes* Heroes::createHero(DefaultStatistics df)
{
	Heroes* hero = NULL;
	std::string className = df.getClassName();
	if (className == "Mage")
	{
		hero = new Mage(df);
	}
	else if (className == "Warrior")
	{
		hero = new Warrior(df);
	}
	else if (className == "Paladin")
	{
		hero = new Paladin(df);
	}
	else if (className == "Tief")
	{
		hero = new Tief(df);
	}
	return hero;
}

Heroes::Heroes(DefaultStatistics df)
{
	this->statistics = df;
}


void Heroes::levelUp()
{
	statistics.setLevel(statistics.getLevel() + 1);
}


void Heroes::showStatistics()
{
	cout << endl;
	cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl << endl;
	cout << "Twoje Statystyki: " << endl;
	cout << "--------------------------------------------------------------" << endl << endl;
	cout << statistics.getHeroName()<< endl;
	cout << "Klasa postaci: " << statistics.getClassName() << endl;
	cout<< "poziom:" << statistics.getLevel() << endl;
	cout << "zloto:" << statistics.getGold() << endl;
	cout << "punkty zycia: " << statistics.getCurrentHp() << "/" << statistics.getHp() << endl;
	cout << "Mana: " << statistics.getCurrentMana() << "/" << statistics.getMana() << endl;
	cout << "atak: " << statistics.getDamage() << endl;
	cout << "sila magiczna:" << statistics.getMagicDamage() << endl;
}


void Heroes::takeDamage(int damage)
{
	statistics.setCurrentHp(statistics.getCurrentHp() - damage);
}

bool Heroes::dead()
{
	if (statistics.getCurrentHp() <= 0)
	{
		return true;
	}
	return false;
}

int Heroes::yourChoice()
{
	string target;
	cout << "Wybierz cel ataku: " << std::endl;
	getline(std::cin >> ws, target);
	int targetIndex;
	if (target == "1" || target == "2" || target == "3")
	{
		istringstream iss(target);
		iss >> targetIndex;
		targetIndex--;
	}
	else
	{
		cout << "prosze wybrac poprawny cel ataku" << endl;
		return yourChoice();
	}
	return targetIndex;
}


