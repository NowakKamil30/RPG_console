#include "CityMenu.h"
#include "ShopMenu.h"
#include <iostream>
#include "FileUse.h"
#include <windows.h>
#include <time.h> 
#include <conio.h>
#include "FightMenu.h"
using namespace std;

CityMenu::CityMenu(FileWork* fw, Heroes* hero):Menu(fw)
{
	this->hero = hero;
}

CityMenu::~CityMenu()
{
}

Heroes* CityMenu::showMenu()
{
	Heroes* heroes=hero;
	cout << endl;
	cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl << endl;
	cout << "MIASTO" << endl;
	cout << "--------------------------------------------------------------" << endl << endl;
	cout << "1. idz do lochow" << endl;
	cout << "2. idz do sklepu" << endl;
	cout << "3. pokaz statystyki" << endl;
	cout << "4. odpocznij (regeneruje mane i punkty zycia kosztuje 100 zlota)" << endl;
	cout << "5.wyjdz z gry" << endl;
	cout << "--------------------------------------------------------------" << endl << endl;
	cout << "co chcesz zrobic?: ";
	heroes = yourChoice();
	return heroes;
}
Heroes* CityMenu::yourChoice()
{
	string choice;
	getline(cin >> ws, choice);
	if (choice == "1")
	{
		FightMenu fm(fw, hero);
		return fm.showMenu();
	}
	else if (choice == "2")
	{
		Menu *menu;
		menu = new ShopMenu(fw,hero);
		return menu->showMenu();

	}
	else if (choice == "3")
	{
		system("cls");
		hero->showStatistics();
		cout << "nacisnij dowolny przycisk zeby wrocic do menu" << endl;
		_getch();
		system("cls");
		return showMenu();

	}
	else if (choice == "4")
	{
		system("cls");
		rest();
		return showMenu();

	}
	else if (choice == "5")
	{
		system("cls");
		cout << "zapraszamy ponownie" << endl;
		Sleep(0.5 * CLOCKS_PER_SEC);
		fw->updateFileDS(hero->statistics,FileWork::heroFile);
		exit(0);
	}
	else
	{
		cout << "prosze wybrac opcje z listy" << endl;
		return yourChoice();
	}
	return hero;
}

void CityMenu::rest()
{
	int currentHp = hero->statistics.getCurrentHp();
	int currentMana= hero->statistics.getCurrentMana();
	int hp = hero->statistics.getHp();
	int mana = hero->statistics.getMana();
	int gold = hero->statistics.getGold();
	if (currentMana == mana && currentHp==hp)
	{
		cout << "jestes wypoczety" << endl;
	}
	else if (gold< 100)
	{
		cout << "nie masz wystarczajacej ilosci zlota" << endl;
	}
	else
	{
		gold -= 100;
		hero->statistics.setGold(gold);
		hero->statistics.setCurrentHp(hp);
		hero->statistics.setCurrentMana(mana);
		cout << "odpoczales twoje statystyki zostaly odnowione" << endl;
		cout << "posiadasz " << gold<< " sztuk zlota" << endl;
	}
}
