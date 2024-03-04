#ifndef ZOMBIE_H
	#define ZOMBIE_H

	#include <iostream>
	class Zombie
	{
		private:
			std::string name;
		public:
			Zombie(const std::string name);
			~Zombie();
			void announce() const;
	};
	Zombie* newZombie(const std::string name);
	void randomChump(const std::string name);
#endif