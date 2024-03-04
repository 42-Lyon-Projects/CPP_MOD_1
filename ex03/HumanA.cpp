#include "HumanA.hpp"

#include <iostream>
#include "HumanA.hpp"


HumanA::HumanA(const std::string &name, const Weapon &weapon) : name(name), weapon(weapon){};



void HumanA::attack() {
	std::cout << this->getName() << " attacks with their " << this->getWeapon().getType();
}
