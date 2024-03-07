#ifndef HARL_HPP
	#define HARL_HPP
	#include <string>

	class Harl
	{
		private:
			void debug(void);
			void info(void);
			void warning(void);
			void error(void);
			std::string names[4];
			void (Harl::*pointers[4])(void);
	public:
			Harl(void);
			void complain(std::string level);
	};

#endif
