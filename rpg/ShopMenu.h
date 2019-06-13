#pragma once
#include "CityMenu.h"
class ShopMenu :
	public CityMenu
{
public:
	ShopMenu(FileWork* fw, Heroes* hero);
	virtual ~ShopMenu();
	virtual Heroes* showMenu();
private:
	virtual Heroes* yourChoice();
};

