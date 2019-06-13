#pragma once
#include "Heroes.h"
#include "FileWork.h"
#include "FileTxt.h"
class Menu
{
protected:
	FileWork* fw;
public:
	Menu(FileWork* fw);
	virtual ~Menu();
	virtual Heroes* showMenu() = 0;
};