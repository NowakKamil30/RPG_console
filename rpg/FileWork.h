#pragma once
#include "DefaultStatistics.h"
class FileWork
{
public:
	static std::string heroFile;
	static std::string listOfTheDead;
	virtual bool createHeroFile(DefaultStatistics defaultStatistics, std::string path) = 0;
	virtual bool updateFileDS(DefaultStatistics defaultStatistics,std::string path)=0;
	virtual void cleanFile(std::string path)=0;
	virtual DefaultStatistics downloadFileDS(std::string path)=0;
	virtual bool showFile(std::string path) = 0;
	virtual bool addToListOfTheDead(DefaultStatistics df,std::string path)=0;
	virtual bool emptyFile(std::string path)=0;
	virtual bool existFile(std::string path) = 0;
	virtual ~FileWork() {};
};

