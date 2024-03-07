#include "Harl.hpp"
#include <iostream>

#include "StringUtils.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: <level> ! \n";
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
		std::cerr << e.what();
		return 1;
	}
	return 0;
}
