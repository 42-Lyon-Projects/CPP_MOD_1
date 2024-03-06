#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string &name) : name(name)
{
	this->weapon = new Weapon();
}

void HumanB::setWeapon(Weapon& weapon) {
	delete this->weapon;
	this->weapon = &weapon;
}

Weapon HumanB::getWeapon() {
	if (this->weapon == NULL || this->weapon->getType().empty())
	{
		Weapon hands = Weapon("Hands");
		return (hands);
	}
	return *this->weapon;
}

std::string HumanB::getName() {
	return this->name;
}

void HumanB::attack() {
	std::cout << this->getName() << " attacks with their " << this->getWeapon().getType() << std::endl;
}
