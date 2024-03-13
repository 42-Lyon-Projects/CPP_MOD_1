#include "Zombie.hpp"

int main()
{
	randomChump("John");
	const Zombie *zombie = newZombie("Lennon");
	if (!zombie)
		return (1);
	zombie->announce();
	delete zombie;
	return (0);
}