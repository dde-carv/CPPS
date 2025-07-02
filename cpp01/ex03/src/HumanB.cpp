#include "HumanB.hpp"

HumanB::HumanB(const std::string name) : _weapon(NULL)
{
	_name = name;
	std::cout << "HumanB constructor called ("<< _name << ")." << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "HumanB default destructor called." << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}
void	HumanB::attack()
{
	if (!_weapon)
		std::cout << _name << " can't attack without a weapon." << std::endl;
	else
		std::cout << _name << " attacks with their " <<  _weapon->getType() << std::endl;
}
