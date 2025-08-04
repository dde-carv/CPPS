#include "FragTrap.hpp"

/************ Constructors and Destructor ************/

FragTrap::FragTrap() : ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << GREEN << "FragTrap (" << _name << ") default constructor called" << RST << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << GREEN << "FragTrap (" << _name << ") costum constructor called" << RST << std::endl;
}

FragTrap::FragTrap(const FragTrap &object) : ClapTrap(object)
{
	*this = object;
	std::cout << GREEN << "FragTrap (" << _name << ") copy constructor called" << RST << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << RED << "FragTrap (" << _name << ") default destructor called" << RST << std::endl;
}

/************ Operator ************/

FragTrap	&FragTrap::operator=(const FragTrap &copy)
{
	if(this != &copy)
	{
		if(this->_name != copy._name)
			_name = copy._name;
		if(this->_hitPoints != copy._hitPoints)
			_hitPoints = copy._hitPoints;
		if(this->_energyPoints != copy._energyPoints)
			_energyPoints = copy._energyPoints;
		if(this->_attackDamage != copy._attackDamage)
			_attackDamage = copy._attackDamage;
	}
	std::cout << YELLOW << "FragTrap (" << _name << ") copy assignment operator called" << RST << std::endl;

	return *this;
}

/************ Member Function ************/

void	FragTrap::highFivesGuys()
{
	if (!_hitPoints)
	{
		std::cout << PURPLE << "FragTrap " << _name << " is dead and can't request high fives." << RST << std::endl;
		return ;
	}
	if (!_energyPoints)
	{
		std::cout << PURPLE << "FragTrap " << _name << " has no energy to request high fives." << RST << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << PURPLE << "FragTrap " << _name << " request the Highest of fives!" << RST <<std::endl;
}
