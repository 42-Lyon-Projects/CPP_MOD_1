#include "HumanA.hpp"

#include <iostream>

HumanA::HumanA(const std::string &name, Weapon& weapon) : name(name), weapon(weapon){};

std::string HumanA::getName() {
	return this->name;
}

Weapon HumanA::getWeapon() {
	return this->weapon;
}

void HumanA::attack() {
	std::cout << this->getName() << " attacks with their " << this->getWeapon().getType() << std::endl;
}
