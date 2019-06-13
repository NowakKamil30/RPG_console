#include "GameOptionMenu.h"
#include "Mage.h"
#include <iostream>
#include <fstream>
using namespace std;
GameOptionMenu::~GameOptionMenu()
{
}
Heroes* GameOptionMenu::showMenu()
{
	std::string difficult;
	DefaultStatistics heroClass;
	std::string heroName;
	cout << endl;
	cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl << endl;
	cout << "Wybierz poziom trudnosci: " << endl;
	cout << "1. latwy" << endl;
	cout << "2. normalny" << endl;
	cout << "3. trudny" << endl;
	cout << "--------------------------------------------------------------" << endl << endl;
	difficult= selectDifficultyLevel();
	cout << endl;
	cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl << endl;
	heroName = setHeroName();
	cout << "--------------------------------------------------------------" << endl << endl;
	cout << "wybierz klase postaci: " << endl;
	cout << "1. Mag" << endl;
	cout << "2. Wojownik" << endl;
	cout << "3. Paladyn" << endl;
	cout << "4. zlodziej" << endl;
	cout << "--------------------------------------------------------------" << endl << endl;
	heroClass = selectClass(heroName,difficult);
	fw->createHeroFile(heroClass,FileWork::heroFile);
	Heroes* hero = Heroes::createHero(heroClass);
	system("cls");
	return hero;
}
DefaultStatistics GameOptionMenu::selectClass(std::string heroName,std::string difficult)
{
	string select;
	cout << "Wybierz swoja klase postaci: ";
	getline(cin >> ws, select);

	
		if(select=="1")
		{
			DefaultStatistics temp(1, 200,200, 150,150, 20, 50, 200, "Mage",heroName, difficult);
			return temp;
		}
		else if(select=="2")
		{
			DefaultStatistics temp(1, 300,300, 50,50, 50, 20, 200, "Warrior", heroName, difficult);
			return temp;
		}
		else if(select=="3")
		{
			DefaultStatistics temp(1, 350,350, 75,75, 35, 35, 200, "Paladin", heroName, difficult);
			return temp;
		}
		else if(select=="4")
		{
			DefaultStatistics temp(1, 250,250,100, 100, 70, 40, 200, "Tief", heroName, difficult);
			return temp;
		}
		else
		{
			cout << "akcja nie rozpoznana" << endl;
			return selectClass(heroName, difficult);
		}
	
}


std::string  GameOptionMenu::selectDifficultyLevel() {
	string select;
	cout << "Wybierz poziom trudnosci: ";
	getline(cin >> ws, select);

		if(select=="1")
		{
			return "easy";
		}
		else if(select=="2")
		{
			return "normal";
		}
		else if(select=="3")
		{
			return "hard";
		}
		else
		{
			cout << "akcja nie rozpoznana" << endl;
			return selectDifficultyLevel();
		}


}

std::string GameOptionMenu::setHeroName()
{
	std::string heroName;
	cout << "imie twojej postaci: ";
	getline(cin >> ws, heroName);
	cout << "Twoja postac nazywa sie: " << heroName << endl;
	return heroName;
}



