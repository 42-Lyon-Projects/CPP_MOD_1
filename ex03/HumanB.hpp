#ifndef HUMANB_HPP
#define HUMANB_HPP

	#include <string>
	#include "Weapon.hpp"
	class HumanB
	{
		private:
			std::string name;
			Weapon* weapon;
		public:
			explicit HumanB(const std::string& name);
			void setWeapon(Weapon& weapon);
			Weapon getWeapon();
			std::string getName();
			void attack();
	};
#endif
