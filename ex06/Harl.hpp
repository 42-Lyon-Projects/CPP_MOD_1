#ifndef HARL_HPP
	#define HARL_HPP
	#include <string>

	class Harl
	{
		private:
			void debug();
			void info();
			void warning();
			void error();
			std::string names[4];
			void (Harl::*pointers[4])();
		public:
			Harl();
			void complain(int level);
			int getIntegerLevel(std::string level);
	};

#endif
