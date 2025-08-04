#include "ScavTrap.hpp"

/************ Constructors and Destructor ************/

ScavTrap::ScavTrap() : ClapTrap(), _guardGate(false)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << GREEN << "ScavTrap (" << _name << ") default constructor called" << RST << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name), _guardGate(false)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << GREEN << "ScavTrap (" << _name << ") costum constructor called" << RST << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &object) : ClapTrap(object)
{
	*this = object;
	std::cout << GREEN << "ScavTrap (" << _name << ") copy constructor called" << RST << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << RED << "ScavTrap (" << _name << ") default destructor called" << RST << std::endl;
}

/************ Operator ************/

ScavTrap	&ScavTrap::operator=(const ScavTrap &copy)
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
		if(this->_guardGate != copy._guardGate)
			_guardGate = copy._guardGate;
	}

	std::cout << YELLOW << "ScavTrap (" << _name << ") copy assignment operator called" << RST << std::endl;

	return *this;
}

/************ Getter ************/

bool	ScavTrap::getGardGate()
{
	return _guardGate;
}

/************ Setter ************/

void	ScavTrap::setGardGate(bool mode)
{
	_guardGate = mode;
}

/************ Member Functions ************/

void	ScavTrap::attack(const std::string& target)
{
	if (!_hitPoints)
	{
		std::cout << BLUE << "ScavTrap " << _name << " is dead and can't attack " << target << "." << RST << std::endl;
		return ;
	}
	if (!_energyPoints)
	{
		std::cout << BLUE << "ScavTrap " << _name << " has no energy to attack " << target << "." << RST << std::endl;
		return ;
	}
	if (!_attackDamage)
	{
		std::cout << BLUE << "ScavTrap " << _name << " is too weak to attack " << target << "." << RST << std::endl;
		return ;
	}
	std::cout << BLUE << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << RST <<std::endl;
	_energyPoints--;
}

void	ScavTrap::guardGate()
{
	if (!_hitPoints)
	{
		std::cout << PURPLE << "ScavTrap " << _name << " is dead and can't guard the gate." << RST << std::endl;
		return ;
	}
	if (!_energyPoints)
	{
		std::cout << PURPLE << "ScavTrap " << _name << " has no energy to guard the gate." << RST << std::endl;
		return ;
	}
	if (_guardGate)
	{
		std::cout << PURPLE << _name << " is already in Gate keeper mode!" << RST << std::endl;
		return ;
	}
	_guardGate = true;
	_energyPoints--;
	std::cout << PURPLE << "ScavTrap " << _name << " switched to Gate keeper mode!" << RST <<std::endl;
}
