#include <iostream>
#include "FileUtils.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Usage: <filename> <string_to_replace> <replaced_by> ! " << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string stringToReplace = argv[2];
	std::string replacedBy = argv[3];

	if (FileUtils::isDirectory(filename))
		return (std::cout << "Error: " << filename << " is a directory" << std::endl, 1);
	if (!FileUtils::fileExists(filename))
		return (std::cout << "Error: " << filename << " file does not exist" << std::endl, 1);

	std::ifstream readFileFlux(filename.c_str());
	if (!readFileFlux.is_open())
		return (std::cout << "Error: " << filename << " could not be opened" << std::endl, 1);

	const size_t linesCount = FileUtils::countLines(readFileFlux);
	std::string* lines = new std::string[linesCount];

	FileUtils::readFromFile(readFileFlux, lines);
	readFileFlux.close();

	for (size_t i = 0; i < linesCount; i++)
	{
		size_t pos = lines[i].find(stringToReplace);
		if(pos != std::string::npos) {
			try
			{
				lines[i].erase(pos, stringToReplace.length());
				try
				{
					lines[i].insert(pos, replacedBy);
				}
				catch(const std::out_of_range& e)
				{
					std::cout << "Exit, an error occured when new string is inserted: " << std::endl;
					std::cout << e.what() << std::endl;
					return 1;
				}
			}
			catch(const std::out_of_range& e)
			{
				std::cout << "Exit, an error occured when the old string is erased: " << std::endl;
				std::cout << e.what() << std::endl;
				return 1;
			}
		}
	}

	std::ofstream writeFileFlux(filename.append(".replace").c_str(), std::ios::trunc);
	if (!writeFileFlux.is_open())
		return (std::cout << "Error: " << filename << " could not be opened" << std::endl, 1);

	FileUtils::writeToFile(writeFileFlux, lines);
	writeFileFlux.close();
	return 0;
}