#include "Zombie.hpp"

Zombie::Zombie()
{
	_name = "default";
	std::cout << "Default constructor called." << std::endl;
}

Zombie::Zombie(std::string name)
{
	_name = name;
	std::cout << "Costum constructor called." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "The zombie " << _name << " destructor was called." << std::endl;
}

void	Zombie::announce()
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
