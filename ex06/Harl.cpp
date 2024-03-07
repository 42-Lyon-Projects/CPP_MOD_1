#include "Harl.hpp"
#include <iostream>

Harl::Harl()
{
	this->names[0] = "DEBUG";
	this->names[1] = "INFO";
	this->names[2] = "WARNING";
	this->names[3] = "ERROR";

	this->pointers[0] = &Harl::debug;
	this->pointers[1] = &Harl::info;
	this->pointers[2] = &Harl::warning;
	this->pointers[3] = &Harl::error;
}

void Harl::complain(int level)
{
	for (size_t i = level; i < 4; i++)
		(this->*pointers[i])();
}

int Harl::getIntegerLevel(std::string level)
{
	for (int i = 0; i < 4; ++i)
	{
		if (this->names[i] == level)
			return i;
	}
	throw std::invalid_argument("Error: " + level + " is not a valid level\n");
}

void Harl::debug()
{
	std::cout << "[ DEBUG ] WOOOOOOOOOW !" << std::endl;
}

void Harl::info()
{
	std::cout << " [INFO ] Hello from the information" << std::endl;
}

void Harl::warning()
{
	std::cerr << "[ WARNING ]Hello this is a Warning message\n";
}

void Harl::error()
{
	std::cerr << "[ ERROR ] >> Hello this in an error\n";
}