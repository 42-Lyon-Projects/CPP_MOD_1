#include "Zombie.hpp"

Zombie	*newZombie(const std::string name)
{
	Zombie	*zombie = new(std::nothrow) Zombie(name) ;
	if (!zombie)
		return (NULL);
	return (zombie);
}