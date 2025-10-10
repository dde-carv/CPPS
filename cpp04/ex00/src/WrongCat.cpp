/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:03:57 by dde-carv          #+#    #+#             */
/*   Updated: 2025/10/10 16:42:08 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << GREEN << "WrongCat default constructor called." << RST << std::endl;
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type)
{
	std::cout << GREEN << "WrongCat costum constructor called." << RST << std::endl;
}

WrongCat::WrongCat(const WrongCat &object) : WrongAnimal(object)
{
	std::cout << GREEN << "WrongCat copy constructor called" << RST << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << RED << "WrongCat default destructor called." << RST << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &copy)
{
	if(this != &copy)
		WrongAnimal::operator=(copy);
	std::cout << YELLOW << "WrongCat copy assignment operator called" << RST << std::endl;

	return *this;
}

void	WrongCat::makeSound() const
{
	std::cout << PURPLE << "Wrong MeeeeEEEEeeeEEeeOOooooOW!" << RST << std::endl;
}
