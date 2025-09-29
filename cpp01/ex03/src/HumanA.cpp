/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 16:58:43 by dde-carv          #+#    #+#             */
/*   Updated: 2025/09/29 16:58:44 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _weapon(weapon)
{
	_name = name;
	std::cout << "HumanA constructor called ("<< _name << ", " << _weapon.getType() << ")." << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "HumanA default destructor called." << std::endl;
}

void	HumanA::setWeapon(Weapon &weapon)
{
	_weapon = weapon;
}

void	HumanA::attack()
{
	std::cout << _name << " attacks with their " <<  _weapon.getType() << std::endl;
}
