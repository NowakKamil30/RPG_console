#pragma once
#include "FileWork.h"
class FileUse :
	public FileWork
{
private:
	FileWork* fw;
public:
	FileUse(FileWork* fw);
	virtual bool createHeroFile(DefaultStatistics defaultStatistics, std::string path);
	virtual bool updateFileDS(DefaultStatistics df, std::string path);
	virtual DefaultStatistics downloadFileDS(std::string path);
	virtual bool showFile(std::string path);
	virtual bool emptyFile(std::string path);
	virtual bool existFile(std::string path);
	virtual void cleanFile(std::string path);
	virtual ~FileUse();
};

