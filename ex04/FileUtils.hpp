#ifndef FILEUTILS_HPP
	#define FILEUTILS_HPP
	#include <string>
	#include <fstream>

	class FileUtils
	{
		public:
			static bool fileExists(std::string filename);
			static bool isDirectory(std::string filename);
			static bool isSymbolicLink(std::string filename);
			static size_t countLines(std::ifstream& fileFlux);
			static void readFromFile(std::ifstream& fileFlux, std::string* lines, size_t linesToRead);
			static void writeToFile(std::ofstream& fileFlux, std::string* lines, size_t linesToWrite);
			static void printFile(std::ifstream& fileFlux);
			static void resetIfStream(std::ifstream& fileFlux);
	};

#endif
