#pragma once
#include "Heroes.h"
class Backpack
{
private:
	int livePotion;
	int manaPotion;
public:
	Backpack(int livePotion = 0, int manaPotion = 0);
	bool canUseLivePostion();
	bool canUseManaPotion();
	int getLivePotion();
	int getManaPotion();
	void setLivePotion(int livePotion);
	void setManaPotion(int manaPotion);
};

