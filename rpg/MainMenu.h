#pragma once
#include "Menu.h"
class MainMenu :
	public Menu
{
public:
	MainMenu(FileWork* fw):Menu(fw){}
	~MainMenu();
	virtual Heroes* showMenu();

private:
	Heroes* yourChoice();
	void showListOfTheDead(std::string file);
};

