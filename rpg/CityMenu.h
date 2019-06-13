#pragma once
#include "Menu.h"
class CityMenu :
	public Menu
{
public:
	CityMenu(FileWork* fw,Heroes* hero);
	virtual ~CityMenu();
	virtual Heroes* showMenu();
protected:
	Heroes* hero;
private:
	Heroes* yourChoice();
	void rest();
};

