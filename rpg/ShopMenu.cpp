#include "ShopMenu.h"
#include<iostream>
using namespace std;
ShopMenu::ShopMenu(FileWork* fw, Heroes* hero):CityMenu(fw,hero){}

ShopMenu::~ShopMenu()
{
}

Heroes* ShopMenu::showMenu()
{
	system("cls");
	cout << endl;
	cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl << endl;
	cout << "SKLEP" << endl;
	cout << "--------------------------------------------------------------" << endl << endl;
	cout << "1.kup +10 do ataku (200 zlota)" << endl;
	cout << "2.kup +20 do sily magicznej (200 zlota)" << endl;
	cout << "3.kup +200 punktow do Many (200 zlota)" << endl;
	cout << "4.kup +100 punktow do zycia (200 zlota)" << endl;
	cout << "5.kup przeskok o level dalej (1000 zlota)" << endl;
	cout << "6.Wyjdz ze sklepu" << endl;
	cout << "Co chcesz zrobic?: ";
	yourChoice();
	return hero;
}

Heroes* ShopMenu::yourChoice()
{
	string choice;
	Heroes* heroes = hero;
	getline(cin >> ws, choice);
	if (choice == "1")
	{
		system("cls");
		if (hero->statistics.getGold() >= 200)
		{
			hero->statistics.setGold(hero->statistics.getGold() - 200);
			hero->statistics.setDamage(hero->statistics.getDamage() + 10);
		}
		else
		{
			cout << "nie masz wystarczaj¹cej ilosci zlota" << endl;
			heroes = showMenu();
		}
	}
	else if (choice == "2")
	{
		system("cls");
		if (hero->statistics.getGold() >= 200)
		{
			hero->statistics.setGold(hero->statistics.getGold() - 200);
			hero->statistics.setMagicDamage(hero->statistics.getMagicDamage() + 20);
		}
		else
		{
			cout << "nie masz wystarczaj¹cej ilosci zlota" << endl;
			heroes = showMenu();
		}
	}
	else if (choice == "3")
	{
		system("cls");
		if (hero->statistics.getGold() >= 200)
		{
			hero->statistics.setGold(hero->statistics.getGold() - 200);
			hero->statistics.setMana(hero->statistics.getMana() + 200);
			hero->statistics.setCurrentMana(hero->statistics.getCurrentMana() + 200);
		}
		else
		{
	
			cout << "nie masz wystarczaj¹cej ilosci zlota" << endl;
			heroes = showMenu();
		}
	}
	else if (choice == "4")
	{
		system("cls");
		if (hero->statistics.getGold() >= 200)
		{
			hero->statistics.setGold(hero->statistics.getGold() - 200);
			hero->statistics.setHp(hero->statistics.getHp() + 100);
			hero->statistics.setCurrentHp(hero->statistics.getCurrentHp() + 100);
		}
		else
		{
			
			cout << "nie masz wystarczaj¹cej ilosci zlota" << endl;
			heroes = showMenu();
		}
	}
	else if (choice == "5")
	{
		system("cls");
		if (hero->statistics.getGold() >= 1000)
		{
			hero->statistics.setGold(hero->statistics.getGold() - 1000);
			hero->levelUp();
		}
		else
		{
			
			cout << "nie masz wystarczaj¹cej ilosci zlota" << endl;
			heroes = showMenu();
		}
	}
	else if (choice == "6")
	{
		system("cls");
		fw->updateFileDS(hero->statistics, FileWork::heroFile);
	}
	else
	{
		cout << "prosze wybrac opcje z listy: ";
		yourChoice();
	}
	return heroes;
}
