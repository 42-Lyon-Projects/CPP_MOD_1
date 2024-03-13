#include "Harl.hpp"
#include <iostream>

#include "StringUtils.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: <level> !" << std::endl;
		return 1;
	}

	Harl harl;
	std::string str = argv[1];
	StringUtils::toUpper(str);

	try
	{
		const int level = harl.getIntegerLevel(str);
		harl.complain(level);
	}
	catch (std::invalid_argument &e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}
	return 0;
}
