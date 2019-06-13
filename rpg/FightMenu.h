#pragma once
#include "CityMenu.h"
#include "FileWork.h"
#include "Heroes.h"
#include "Moster.h"
class FightMenu :
	public CityMenu
{
protected:
	Moster *mosters[3];
public:
	FightMenu(FileWork* fw, Heroes* hero);
	virtual ~FightMenu();
	virtual Heroes* showMenu();
private:
	Heroes* yourChoice();
	Moster* createEnemy();
	void showYourEnemy();
	void takeDamage(FightData df);
	void takeDamage(FightData df, int index);

};

