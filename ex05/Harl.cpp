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
	std::cout << "Error: " << level << " is not a valid level" << std::endl;
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
	std::cout << "Hello this is a Warning message" << std::endl;
}

void Harl::error()
{
	std::cout << "[ERROR] >> Hello this in an error" << std::endl;
}