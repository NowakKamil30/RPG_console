#include "MainMenu.h"
#include "GameOptionMenu.h"
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

MainMenu::~MainMenu() {}
Heroes* MainMenu::showMenu()
{
		cout << endl;
		cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl << endl;
		cout << "Super RPG" << endl << endl;
		cout << "--------------------------------------------------------------" << endl;
		cout << "--------------------------------------------------------------" << endl << endl;
		cout << "1. graj!!" << endl;
		cout << "2. zobacz liste zmarlych." << endl;
		cout << "3. wyjdz z gry" << endl;
		cout << "--------------------------------------------------------------" << endl << endl;
		return yourChoice();
}
Heroes* MainMenu::yourChoice()
{
	Heroes* hero=NULL;
	string choice;
	cout << "wybierz opcje: ";
	getline(cin >> ws, choice);

	if(choice=="1")
	{
		if (!fw->existFile(FileWork::heroFile) || fw->emptyFile(FileWork::heroFile))
		{
			cout << "tworze plik";
			GameOptionMenu gameOptionMenu(fw);
			hero = gameOptionMenu.showMenu();
			return hero;
		}
		else
		{
			DefaultStatistics temp=fw->downloadFileDS(FileWork::heroFile);
			cout << "wczytuje" << endl;
			hero = Heroes::createHero(temp);
			system("cls");
			return hero;
		}
	}
	else if(choice=="2")
	{
		showListOfTheDead(FileWork::listOfTheDead);
	}
	else if(choice=="3")
	{
		exit(0);
	}
	else
	{
		cout << "akcja nie rozpoznana" << endl;
		hero=yourChoice();
	}
	system("cls");
	return hero;
}
void MainMenu::showListOfTheDead(std::string file)
{
	cout << endl;
	cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl << endl;
	if (!fw->existFile(file) || fw->emptyFile(file))
	{
		cout << "Jeszcze nikt nie umarl" << endl;
	}
	else
	{
		if (!fw->showFile(file))
		{
			cout << "error nie udalo sie odczytac pliku" << endl;
		}
	}
	cout << "nacisnij dowolny przycisk zeby wrocic do glownego menu" << endl;
	_getch();
	system("cls");
	showMenu();

}
