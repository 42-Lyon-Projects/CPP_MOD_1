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

	harl.complain(str);
	return 0;
}
