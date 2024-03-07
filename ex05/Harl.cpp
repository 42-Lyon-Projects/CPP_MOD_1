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

void Harl::complain(std::string level)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (this->names[i] == level)
		{
			(this->*pointers[i])();
			return;
		}
	}
	std::cerr << "Error: " << level << " is not a valid level\n";
}

void Harl::debug()
{
	std::cout << "[DEBUG] WOOOOOOOOOW !" << std::endl;
}

void Harl::info()
{
	std::cout << "Hello from the information" << std::endl;
}

void Harl::warning()
{
	std::cerr << "Hello this is a Warning message\n";
}

void Harl::error()
{
	std::cerr << "[ERROR] >> Hello this in an error\n";
}