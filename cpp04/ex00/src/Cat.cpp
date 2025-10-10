/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:03:45 by dde-carv          #+#    #+#             */
/*   Updated: 2025/10/10 16:42:08 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << GREEN << "Cat default constructor called." << RST << std::endl;
}

Cat::Cat(std::string type) : Animal(type)
{
	std::cout << GREEN << "Cat costum constructor called." << RST << std::endl;
}

Cat::Cat(const Cat &object) : Animal(object)
{
	std::cout << GREEN << "Cat copy constructor called" << RST << std::endl;
}

Cat::~Cat()
{
	std::cout << RED << "Cat default destructor called." << RST << std::endl;
}

Cat	&Cat::operator=(const Cat &copy)
{
	if(this != &copy)
		Animal::operator=(copy);
	std::cout << YELLOW << "Cat copy assignment operator called" << RST << std::endl;

	return *this;
}

void	Cat::makeSound() const
{
	std::cout << PURPLE << "MeeeeEEEEeeeEEeeOOooooOW!" << RST << std::endl;
}
