// rpg.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include "Menu.h"
#include "MainMenu.h"
#include "Heroes.h"
#include "Mage.h"
#include "FileTxt.h"
#include "CityMenu.h"
#include <time.h>
using namespace std;
int main()
{
	while (true)
	{
		srand(time(NULL));
		FileWork* file = new FileTxt();
		Menu* menuUse = new MainMenu(file);
		Heroes* hero = menuUse->showMenu();
		while (hero != NULL)
		{
			menuUse = new CityMenu(file, hero);
			hero = menuUse->showMenu();
		}

	}
}

