#include <iostream>

int main()
{
	const std::string line = "HI THIS IS BRAIN";
	const std::string *stringPTR = &line;
	const std::string stringREF = *stringPTR;

	std::cout << "Memory address of string :" << &line << std::endl;
	std::cout << "Memory address held by stringPTR :" << stringPTR << std::endl;
	std::cout << "Memory address held by stringREF :" << &stringREF << std::endl;

	std::cout << "Value of string :" << line << std::endl;
	std::cout << "Value pointed by stringPTR :" << *stringPTR << std::endl;
	std::cout << "value pointed by stringREF :" << stringREF << std::endl;
}