#ifndef HUMANA_HPP
#define HUMANA_HPP

	#include <string>
	#include "Weapon.hpp"
	class HumanB
	{
		private:
			std::string name;
			Weapon weapon;
		public:
			Human(const std::string name);
			Weapon getWeapon();
			std::string getName();
			void attack();
	};
#endif
