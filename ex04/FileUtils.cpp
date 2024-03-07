#include "FileUtils.hpp"

#include <fstream>
#include <sys/stat.h>
#include <iostream>


bool FileUtils::fileExists(std::string filename)
{
	std::ifstream file(filename.c_str());
	const bool exists = file.good() && file.is_open();
	file.close();
	return exists;
}

bool FileUtils::isDirectory(std::string filename)
{
	struct stat buff = {};
	if(stat(filename.c_str(), &buff) == 0)
		return buff.st_mode & S_IFDIR;
	// If stat fails, assume it's not a directory
	return false;
}

bool FileUtils::isSymbolicLink(std::string filename)
{
	struct stat buff = {};
	if(stat(filename.c_str(), &buff) == 0)
		return (buff.st_mode & S_IFLNK);
	// If stat fails, assume it's not a symbolic link
	return false;
}

size_t FileUtils::countLines(std::ifstream& fileFlux)
{
	size_t count = 0;
	std::string line;
	while(std::getline(fileFlux, line))
		count++;
	return count;
}

void FileUtils::readFromFile(std::ifstream& fileFlux, std::string lines[])
{
	size_t i = 0;
	while(std::getline(fileFlux, lines[i++]))
		;
}

void FileUtils::writeToFile(std::ofstream& fileFlux, std::string lines[])
{

	size_t i = 0;
	while(!lines[i].empty())
		fileFlux << lines[i++] << std::endl;
}

void FileUtils::printFile(std::ifstream&  fileFlux)
{
	std::string line;
	while(std::getline(fileFlux, line))
		std::cout << line;
}
