#include "FileUse.h"

FileUse::FileUse(FileWork* fw)
{
	this->fw = fw;
}

bool FileUse::createHeroFile(DefaultStatistics defaultStatistics, std::string path)
{
	return fw->createHeroFile(defaultStatistics,path);
}

bool FileUse::updateFileDS(DefaultStatistics df, std::string path)
{
	return fw->updateFileDS(df, path);
}

DefaultStatistics FileUse::downloadFileDS(std::string path)
{
	return fw->downloadFileDS(path);
}

bool FileUse::showFile(std::string path)
{
	return fw->showFile(path);
}

bool FileUse::emptyFile(std::string path)
{
	return fw->emptyFile(path);
}

bool FileUse::existFile(std::string path)
{
	return fw->existFile(path);
}

void FileUse::cleanFile(std::string path)
{
	fw->cleanFile(path);
}

FileUse::~FileUse()
{
}
