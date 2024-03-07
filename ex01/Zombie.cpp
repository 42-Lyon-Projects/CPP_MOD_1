#include "Zombie.hpp"

Zombie::Zombie() {};
Zombie::Zombie(const std::string name) : name(name) {}

Zombie::~Zombie()
{
	std::cout << name << " has been destroyed" << std::endl;
}

void Zombie::announce() const
{
	if (!this->name.empty())
		std::cout << name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
	this->name = name;
}

