#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	_type = type;
	std::cout << "Weapon constructor called (" << _type << ")." << std::endl;
}

Weapon::~Weapon()
{
	std::cout << "Weapon default destructor called." << std::endl;
}

const std::string&	Weapon::getType()
{
	return _type;
}

void	Weapon::setType(std::string type)
{
	_type = type;
}
