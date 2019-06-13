#include "FightData.h"

FightData::FightData(int damage[4], int health[4])
{
	for (int i = 0; i < 4; i++)
	{
		this->damage[i] = damage[i];
		this->health[i] = health[i];
	}

}

FightData::FightData()
{
	for (int i = 0; i < 4; i++)
	{
		this->damage[i] = 0;
		this->health[i] = 0;
	}
}


