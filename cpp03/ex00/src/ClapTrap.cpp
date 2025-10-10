/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:01:40 by dde-carv          #+#    #+#             */
/*   Updated: 2025/10/10 16:42:08 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

/************ Constructors and Destructor ************/

ClapTrap::ClapTrap() : _name("Jeff") , _hitPoints(10) , _energyPoints(10) , _attackDamage(0)
{
	std::cout << GREEN << "Default constructor called" << RST << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name) , _hitPoints(10) , _energyPoints(10) , _attackDamage(0)
{
	std::cout << GREEN << "Costum constructor called" << RST << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &object)
{
	*this = object;

	std::cout << GREEN << "Copy constructor called" << RST << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << RED << "Default destructor called" << RST << std::endl;
}

/************ Getters ************/

std::string	ClapTrap::getName()
{
	return _name;
}

unsigned int	ClapTrap::getHitPoints()
{
	return _hitPoints;
}

unsigned int	ClapTrap::getEnergyPoints()
{
	return _energyPoints;
}

unsigned int	ClapTrap::getAttackDamage()
{
	return _attackDamage;
}

/************ Setters ************/

void	ClapTrap::setName(std::string name)
{
	_name = name;
}

void	ClapTrap::setHitPoints(unsigned int hp)
{
	_hitPoints = hp;
}

void	ClapTrap::setEnergyPoints(unsigned int ep)
{
	_energyPoints = ep;
}

void	ClapTrap::setAttackDamage(unsigned int ad)
{
	_attackDamage = ad;
}

/************ Operator ************/

ClapTrap	&ClapTrap::operator=(const ClapTrap &copy)
{
	if(this == &copy)
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
	else
	{
		_name = copy._name;
		_hitPoints = copy._hitPoints;
		_energyPoints = copy._energyPoints;
		_attackDamage = copy._attackDamage;
	}

	std::cout << YELLOW << "ClapTrap (" << _name << ") copy assignment operator called" << RST << std::endl;

	return *this;
}

/************ Member Functions ************/

void	ClapTrap::attack(const std::string& target)
{
	if (!_hitPoints)
	{
		std::cout << BLUE << "ClapTrap " << _name << " is dead and can't attack " << target << "." << RST << std::endl;
		return ;
	}
	if (!_energyPoints)
	{
		std::cout << BLUE << "ClapTrap " << _name << " has no energy points to attack " << target << "." << RST << std::endl;
		return ;
	}
	if (!_attackDamage)
	{
		std::cout << BLUE << "ClapTrap " << _name << " is too weak to attack " << target << "." << RST << std::endl;
		return ;
	}
	std::cout << BLUE << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << RST <<std::endl;
	_energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (!_hitPoints)
	{
		std::cout << CYAN << "ClapTrap " << _name << " is already dead, can't attack this one!!" << RST << std::endl;
		return ;
	}
	if ((int)(_hitPoints - amount) < 0)
		amount = _hitPoints;
	_hitPoints -= amount;
	std::cout << CYAN << "ClapTrap " << _name << " lost " << amount << " hit points while getting attacked!" << RST << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!_hitPoints)
	{
		std::cout << PURPLE << "ClapTrap " << _name << " is dead and cannot be repaired!" << RST << std::endl;
		return ;
	}
	if (!_energyPoints)
	{
		std::cout << PURPLE << "ClapTrap " << _name << " doesn't have energy points to be repaired!" << RST << std::endl;
		return ;
	}
	_hitPoints += amount;
	_energyPoints--;
	std::cout << PURPLE << "ClapTrap " << _name << " has repaired and gained " << amount << " hit points back!" << RST << std::endl;
}
