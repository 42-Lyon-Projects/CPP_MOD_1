
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
	std::string StringToReplace = argv[2];
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

	readFileFlux.seekg(0, std::ios::beg);
	readFileFlux.clear();


	FileUtils::readFromFile(readFileFlux, lines);
	std::cout << "First string: " << lines[0] << std::endl;

	readFileFlux.close();

	std::ofstream writeFileFlux(filename.append(".replace").c_str(), std::ios::trunc);
	if (!writeFileFlux.is_open())
		return (std::cerr << "Error: " << filename << " could not be opened\n", 1);

	FileUtils::writeToFile(writeFileFlux, lines);
	writeFileFlux.close();
	return 0;
}