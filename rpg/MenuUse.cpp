#include "MenuUse.h"

MenuUse::MenuUse(Menu* menu)
{
	this->menu = menu;
}

MenuUse::~MenuUse()
{
}

Heroes* MenuUse::showMenu()
{
	return menu->showMenu();
}
