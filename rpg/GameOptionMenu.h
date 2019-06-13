#pragma once
#include "Menu.h"
#include <string>
#include "DefaultStatistics.h"
#include "Heroes.h"
class GameOptionMenu :
	public Menu
{
public:
	GameOptionMenu(FileWork* fw) :Menu(fw) {};
	virtual ~GameOptionMenu();
	virtual Heroes* showMenu();
private:
	DefaultStatistics selectClass(std::string heroName, std::string difficult);
	std::string selectDifficultyLevel();
	std::string setHeroName();
};
