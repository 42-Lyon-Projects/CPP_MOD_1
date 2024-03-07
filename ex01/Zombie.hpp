#ifndef ZOMBIE_H
	#define ZOMBIE_H

	#include <iostream>
	class Zombie
	{
		private:
			std::string name;
		public:
			Zombie(const std::string name);
			Zombie();
			~Zombie();
			void announce() const;
			void setName(std::string name);
	};
	Zombie* zombieHorde(int N, std::string name);

#endif