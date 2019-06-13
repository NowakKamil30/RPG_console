#include "FileTxt.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
bool FileTxt::createHeroFile(DefaultStatistics defaultStatistics, std::string path)
{
	fstream file;
	bool good;
	std::string correctPath = path + ".txt";
	file.open(correctPath, ios::out);
	if (file.good())
	{
		double difficult = defaultStatistics.getDifficultValue();
		file << defaultStatistics.getLevel() << endl;
		file << defaultStatistics.getHp() * difficult << endl;
		file << defaultStatistics.getCurrentHp() * difficult << endl;
		file << defaultStatistics.getMana() * difficult << endl;
		file << defaultStatistics.getCurrentMana() * difficult << endl;
		file << defaultStatistics.getDamage() * difficult << endl;
		file << defaultStatistics.getMagicDamage() * difficult << endl;
		file << defaultStatistics.getGold() * difficult << endl;
		file << defaultStatistics.getClassName() << endl;
		file << defaultStatistics.getHeroName() << endl;
		file << defaultStatistics.getDifficultName() << endl;
		good = true;
	}
	else
	{
		good = false;
	}
	file.close();
	return good;
}

bool FileTxt::updateFileDS(DefaultStatistics defaultStatistics, std::string path)
{
	fstream file;
	bool good;
	std::string correctPath = path + ".txt";
	file.open(correctPath, ios::out);
	if (file.good())
	{
		file << defaultStatistics.getLevel() << endl;
		file << defaultStatistics.getHp()<< endl;
		file << defaultStatistics.getCurrentHp()<< endl;
		file << defaultStatistics.getMana()<< endl;
		file << defaultStatistics.getCurrentMana()<< endl;
		file << defaultStatistics.getDamage() << endl;
		file << defaultStatistics.getMagicDamage()<< endl;
		file << defaultStatistics.getGold()<< endl;
		file << defaultStatistics.getClassName()<< endl;
		file << defaultStatistics.getHeroName()<< endl;
		file << defaultStatistics.getDifficultName()<< endl;
		good = true;
	}
	else
	{
		good = false;
	}
	file.close();
	return good;
}

DefaultStatistics FileTxt::downloadFileDS(std::string path)
{
	fstream file;
	DefaultStatistics df;
	std::string correctPath = path + ".txt";
	file.open(correctPath, ios::in);
	if (file.good())
	{
		int temp=0;
		file >> temp;
		df.setLevel(temp);
		file >> temp;
		df.setHp(temp);
		file >> temp;
		df.setCurrentHp(temp);
		file >> temp;
		df.setMana(temp);
		file >> temp;
		df.setCurrentMana(temp);
		file >> temp;
		df.setDamage(temp);
		file >> temp;
		df.setMagicDamage(temp);
		file >> temp;
		df.setGold(temp);
		std::string temporary;
		getline(file, temporary);
		getline(file, temporary);
		df.setClassName(temporary);
		getline(file, temporary);
		df.setHeroName(temporary);
		getline(file, temporary);
		df.setDifficultName(temporary);
	}
	file.close();
	return df;
}

bool FileTxt::showFile(std::string path)
{
	fstream file;
	bool good;
	std::string correctPath = path + ".txt";
	file.open(correctPath, ios::in);
	if (file.good())
	{
		good = true;
		while (!file.eof())
		{
			string dane;
			getline(file, dane);
			cout << dane << endl;
		}
	}
	else
	{
		good = false;
	}
	file.close();
	return good;
}

bool FileTxt::emptyFile(std::string path)
{
	fstream file;
	bool empty;
	std::string correctPath = path + ".txt";
	file.open(correctPath, ios::in);
	file.seekg(0, ios::end);
	if (file.tellg()==0)
	{
		empty = true;
	}
	else
	{
		empty = false;
	}
	file.close();
	return empty;
}

bool FileTxt::existFile(std::string path)
{
	fstream file;
	bool exist;
	std::string correctPath = path + ".txt";
	file.open(correctPath, ios::in);
	if (file.good())
	{
		exist = true;
	}
	else
	{
		exist = false;
	}
	file.close();
	return exist;
}

void FileTxt::cleanFile(std::string path)
{
	fstream file;
	std::string correctPath = path + ".txt";
	file.open(correctPath, ios::out);
	file.close();
}

bool FileTxt::addToListOfTheDead(DefaultStatistics df,std::string path)
{
	fstream file;
	bool good=false;
	std::string correctPath = path + ".txt";
	file.open(correctPath, ios::out | ios::app);
	if (file.good())
	{
		good = true;
		file << df.getHeroName() << ": " << endl;
		file <<"klasa postaci: "<<df.getClassName() <<"|| level: " << df.getLevel() << endl;
		file << "poziom trudnosci: " << df.getDifficultName() << endl;
	}
	return good;
}

FileTxt::~FileTxt()
{
}

