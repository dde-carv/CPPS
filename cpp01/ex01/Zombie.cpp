/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 16:57:48 by dde-carv          #+#    #+#             */
/*   Updated: 2025/09/29 16:57:49 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	Zombie::setName(std::string name)
{
	_name = name;
}
