#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _weapon(weapon)
{
	_name = name;
	std::cout << "HumanA constructor called ("<< _name << ", " << _weapon.getType() << ")." << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "HumanA destructor called." << std::endl;
}

void	HumanA::setWeapon(Weapon &weapon)
{
	_weapon = weapon;
}

void	HumanA::attack()
{
	std::cout << _name << " attacks with their " <<  _weapon.getType() << std::endl;
}
