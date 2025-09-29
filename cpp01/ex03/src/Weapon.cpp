/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 16:58:52 by dde-carv          #+#    #+#             */
/*   Updated: 2025/09/29 16:58:53 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
