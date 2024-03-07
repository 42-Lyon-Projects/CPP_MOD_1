
#include "FileUtils.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: <filename> <string_to_replace> <replaced_by> ! \n";
		return 1;
	}

	std::string filename = argv[1];
	std::string stringToReplace = argv[2];
	std::string replacedBy = argv[3];

	if (FileUtils::isDirectory(filename))
		return (std::cerr << "Error: " << filename << " is a directory\n", 1);
	if (!FileUtils::isSymbolicLink(filename))
		return (std::cerr << "Error: " << filename << " is a symbolic link\n", 1);
	if (!FileUtils::fileExists(filename))
		return (std::cerr << "Error: " << filename << " does not exist\n", 1);

	std::ifstream readFileFlux(filename.c_str());
	if (!readFileFlux.is_open())
		return (std::cerr << "Error: " << filename << " could not be opened\n", 1);

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
					std::cerr << "Exit, an error occured when new string is inserted: \n";
					std::cerr << e.what() << '\n';
					return 1;
				}
			}
			catch(const std::out_of_range& e)
			{
				std::cerr << "Exit, an error occured when the old string is erased: \n";
				std::cerr << e.what() << '\n';
				return 1;
			}
		}
	}

	std::ofstream writeFileFlux(filename.append(".replace").c_str(), std::ios::trunc);
	if (!writeFileFlux.is_open())
		return (std::cerr << "Error: " << filename << " could not be opened\n", 1);

	FileUtils::writeToFile(writeFileFlux, lines);
	writeFileFlux.close();
	return 0;
}