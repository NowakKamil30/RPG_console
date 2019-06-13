#include "Backpack.h"

Backpack::Backpack(int livePotion, int manaPotion)
{
	this->livePotion = livePotion;
	this->manaPotion = manaPotion;
}



bool Backpack::canUseLivePostion()
{
	if (livePotion > 0)
	{
		return true;
	}
	return false;
}



bool Backpack::canUseManaPotion()
{
	if (manaPotion > 0)
	{
		return true;
	}
	return false;
}

int Backpack::getLivePotion()
{
	return livePotion;
}

int Backpack::getManaPotion()
{
	return manaPotion;
}

void Backpack::setLivePotion(int livePotion)
{
	this->livePotion = livePotion;
}

void Backpack::setManaPotion(int manaPotion)
{
	this->manaPotion = manaPotion;
}
