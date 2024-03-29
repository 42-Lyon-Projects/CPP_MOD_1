#include <iostream>
#include <cstdlib>
#include "FileUtils.hpp"
#include "StringUtils.hpp"

static void checkIfArgsIsValid(int argc, char **argv)
{
	if (argc != 4)
		throw std::invalid_argument("Arguments <original_file> <replaced> <by>");

	std::string filename = argv[1];
	std::string stringToReplace = argv[2];
	std::string replacedBy = argv[3];

	if (filename.empty() || StringUtils::isOnlyWhitespace(filename) || !StringUtils::isPrintable(filename))
		throw std::invalid_argument("Filename is invalid !");
	if (stringToReplace.empty() || !StringUtils::isPrintable(stringToReplace))
		throw std::invalid_argument("StringToReplace is invalid !");
	if (!StringUtils::isPrintable(replacedBy))
		throw std::invalid_argument("StringReplacedBy is invalid !");
	if (FileUtils::isDirectory(filename))
		throw std::invalid_argument("File can't be a folder");
}


static void replaceStringArray(size_t linesCount, std::string *lines, const std::string &key, const std::string &value)
{
	const std::size_t keyLen = key.length();
	const std::size_t valueLen = value.length();

	try {
		for (size_t lineIndex = 0; lineIndex < linesCount; lineIndex++) {
			const std::size_t stringLen = lines[lineIndex].length();
			for (std::size_t charIndex = 0; charIndex < stringLen; charIndex++) {
				size_t pos = lines[lineIndex].find(key, charIndex);
				if (pos == std::string::npos)
					continue;
				lines[lineIndex].erase(pos, keyLen);
				lines[lineIndex].insert(pos, value);
				charIndex = pos + valueLen;
			}
		}
	}
	catch (const std::exception &e) {
		std::string trace = "Exception throws during replace :";
		trace.append(e.what());
		throw std::out_of_range(trace);
	}
}

int main(int argc, char **argv)
{
	std::string *lines;
	bool mustFree = false;

	try {
		checkIfArgsIsValid(argc, argv);
		std::string filename = argv[1];
		std::string stringToReplace = argv[2];
		std::string replacedBy = argv[3];

		std::ifstream readFileFlux(filename.c_str());
		if (!readFileFlux.is_open())
			return (std::cout << "Error: " << filename << " could not be opened" << std::endl, 1);
		const size_t linesCount = FileUtils::countLines(readFileFlux);
		lines = new std::string[linesCount];
		mustFree = true;
		FileUtils::readFromFile(readFileFlux, lines, linesCount);
		replaceStringArray(linesCount, lines, stringToReplace, replacedBy);

		std::ofstream writeFileFlux(filename.append(".replace").c_str(), std::ios::trunc);
		if (!writeFileFlux.is_open()) {
			delete[] lines;
			mustFree = false;
			return (std::cout << "Error: " << filename << " could not be opened" << std::endl, 1);
		}

		FileUtils::writeToFile(writeFileFlux, lines, linesCount);
		delete[] lines;
		mustFree = false;
		writeFileFlux.close();
	}
	catch (std::exception &ex) {
		if (mustFree)
			delete [] lines;
		std::cout << ex.what() << std::endl;
		return 1;
	}
	return 0;
}