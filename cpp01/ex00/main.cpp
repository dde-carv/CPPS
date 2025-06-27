#include "Zombie.hpp"

int	main()
{
	std::cout << "Creating a Zombie in the stack." << std::endl;
	Zombie half_dead("Gostavo");
	half_dead.announce();

	std::cout << std::endl << "Creating a Zombie in the heap." << std::endl;
	Zombie *other_half = newZombie("Rita");
	other_half->announce();

	std::cout << std::endl << "Creating a Zombie outside the scope." << std::endl;
	randomChump("Ronaldo");

	delete other_half;
}
