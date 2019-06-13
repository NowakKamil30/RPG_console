#pragma once
#include "Menu.h"
class MenuUse :
	public Menu
{
public:
	MenuUse(Menu* menu);
	virtual ~MenuUse();
	virtual Heroes* showMenu();
private:
	Menu* menu;
};

