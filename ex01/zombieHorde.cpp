#include "Zombie.hpp"

Zombie* zombieHorde(const int N, const std::string name)
{
	Zombie *zombies = new (std::nothrow) Zombie[N];
	if (!zombies)
		return (NULL);
	for (int i = 0; i < N; ++i)
		zombies[i].setName(name);
	return zombies;
}