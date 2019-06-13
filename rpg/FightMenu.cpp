#include "FightMenu.h"
#include "Vampire.h"
#include "Skeleton.h"
#include "Spider.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h> 
using namespace std;

FightMenu::FightMenu(FileWork* fw, Heroes* hero):CityMenu(fw,hero)
{
	for (int i = 0; i < 3; i++)
	{
		mosters[i] = createEnemy();
	}
	system("cls");
}

FightMenu::~FightMenu(){}

Heroes* FightMenu::showMenu()
{
	Heroes* heroes = hero;
	cout << endl;
	cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl << endl;
	cout << "Loch poziom: "<<hero->statistics.getLevel() << endl;
	cout << "--------------------------------------------------------------" << endl << endl;
	cout << "walczysz" << endl;
	showYourEnemy();
	cout <<hero->statistics.getHeroName()<< ":"<<endl;
	cout << "punkty zycia: " << hero->statistics.getCurrentHp() << " / " << hero->statistics.getHp() << endl;
	cout << "punkty many: " << hero->statistics.getCurrentMana() << " / " << hero->statistics.getMana() << endl;
	cout << "1. atakuj(" << hero->statistics.getDamage() << ")" << endl;
	cout << "2. pokaz zaklecia" << endl;
	heroes=yourChoice();
	return heroes;
}

Heroes* FightMenu::yourChoice()
{
	string choice;
	FightData df;
	getline(cin >> ws, choice);
	if (choice == "1")
	{
		df=hero->attack();
	}
	else if (choice == "2")
	{
		df=hero->spellMenu();
		
	}
	else
	{
		cout << "prosze wybrac opcje z listy: ";
		yourChoice();
	}
	takeDamage(df);
	bool fight = false;
	system("cls");
	for (int i = 0; i < 3; i++)
	{
		if (!mosters[i]->dead())
		{
			int specialattack = rand() % 2;
			cout << mosters[i]->getName() << ": ";
			if (specialattack == 1)
			{
				df = mosters[i]->specialAttack();
			}
			else
			{
				df = mosters[i]->attack();
			}
			takeDamage(df, i);
			fight = true;
		}
	}
	if (hero->dead())
	{
		if (fw->addToListOfTheDead(hero->statistics, FileWork::listOfTheDead))
		{
			fw->cleanFile(FileWork::heroFile);
			cout << "Twoja postac zginela :/" << endl;
			cout << "nacisnij dowolny przcisk aby wrocic do menu glownego" << endl;
			_getch();
			system("cls");

		}
		else
		{
			cout << "wystapil blad zapisu program zostanie zamkniety" << endl;
			Sleep(1 * CLOCKS_PER_SEC);
			exit(0);
		}
		return NULL;

	}
	if (fight == false)
	{
		hero->levelUp();
		fw->updateFileDS(hero->statistics, FileWork::heroFile);
		cout << "wygrales bitwne i awansowales na nowy level!!!!!!" << endl;
		hero->showStatistics();
		cout << "nacisnij dowolny przycisk zeby wrocic do miasta" << endl;
		_getch();
		system("cls");
		return hero;
	}
	else
	{
		return showMenu();
	}
	
	return hero;
}

Moster* FightMenu::createEnemy()
{
	Moster* moster;
	int level = hero->statistics.getLevel();
	int random = rand() % 100;
	if (random < 50)
	{
		
		moster = new Spider(level);
	}
	else if (random < 90)
	{
		moster = new Skeleton(level);
	}
	else
	{
		moster = new Vampire(level);
	}
	return moster;
}

void FightMenu::showYourEnemy()
{
	for (int i = 0; i < 3; i++)
	{
		cout << i+1<<"." << mosters[i]->getName() << ' ' << mosters[i]->getCurrentHp()<< "/" << mosters[i]->getHp() << endl;
	}
}

void FightMenu::takeDamage(FightData df)
{
	for (int i = 0; i < 3; i++)
	{
		mosters[i]->takeDamage(df.damage[i]-df.health[i]);
	}
	hero->takeDamage(df.damage[3]-df.health[3]);
}

void FightMenu::takeDamage(FightData df, int index)
{
	int k = index;
	for (int i = 0; i < 3; i++)
	{
		mosters[k]->takeDamage(df.damage[i] - df.health[i]);
		if (k == 2)
		{
			k = 0;
		}
	}
	hero->takeDamage(df.damage[3] - df.health[3]);
}
